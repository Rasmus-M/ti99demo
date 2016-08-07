// convertpic.cpp : Defines the entry point for the console application.
// hacky tool to read in the demo title page and convert it so that the
// foreground data is always the data we want to pour. Color table is set
// to foreground on cyan just so we can see it, but is not used anymore

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>

unsigned char pat[6144+128], col[6144+128];

unsigned char *RLEEncode(unsigned char *pbuf, int *nSize, int InSize) {
	int nOffset=0;
	int nOutputSize=0;
	unsigned char *pRet = (unsigned char*)malloc(InSize*2);	// worst case
	while (nOffset < InSize) {
		// decide whether to do a run or data
		if ((pbuf[nOffset]==pbuf[nOffset+1]) && (pbuf[nOffset] == pbuf[nOffset+2])) {
			// worth doing an RLE run
			// work out for how far!
			int i=nOffset+3;
			while (pbuf[i] == pbuf[nOffset]) {
				i++;
				if (i>=InSize) break;
				if (i-nOffset >= 127) break;
			}
			pRet[nOutputSize++] = 0x80|(i-nOffset);
			pRet[nOutputSize++] = pbuf[nOffset];
			nOffset=i;
		} else {
			// not worth doing RLE -- see for how long
			int i=nOffset+1;
			while ((pbuf[i]!=pbuf[i+1]) || (pbuf[i] != pbuf[i+2])) {
				i++;
				if (i>=InSize) break;
				if (i-nOffset >= 127) break;
			}
			pRet[nOutputSize++] = i-nOffset;
			for (int c=0; c<i-nOffset; c++) {
				pRet[nOutputSize++] = pbuf[nOffset+c];
			}
			nOffset=i;
		}
	}
	*nSize = nOutputSize;
	printf("RLE compress table from %d to %d bytes\n", InSize, nOutputSize);
	return pRet;
}


int main(int argc, char* argv[])
{
	FILE *fp=fopen("C:\\WORK\\TI\\megademo\\ti99demo\\DONTMESS.TIAC", "rb");
	if (6144+128 != fread(col, 1, 6144+128, fp)) {
		printf("failed to read color\n");
		return 1;
	}
	fclose(fp);
	fp=fopen("C:\\WORK\\TI\\megademo\\ti99demo\\DONTMESS.TIAP", "rb");
	if (6144+128 != fread(pat, 1, 6144+128, fp)) {
		printf("failed to read pattern\n");
		return 1;
	}
	fclose(fp);

	int offset = 128;
	for (int row = 0; row < 24; row++) {
		for (int column=0; column<32; column++) {
			for (int byte=0; byte<8; byte++) {
				// now we can look at each byte and decide what it SHOULD be
				// it's pretty simple... it's white except rows 5-18 are black
				if ((column < 5) || (column > 26)) {
					// nothing here, make it black and empty
					col[offset]=0x11;
					pat[offset]=0x00;
				} else if ((row > 4) && (row < 19)) {
					// this is the text area - black pixels on white (grey for one row!)
					if (((col[offset]&0xff)==0x00)||((col[offset]&0xff)==0x11)||((col[offset]&0xff)==0xee)) {
						// solid - make sure pixels are set
						pat[offset] = 0xff;
					} else if (((col[offset]&0xf0)==0x00)||((col[offset]&0xf0)==0x10)||((col[offset]&0xf0)==0xe0)) {
						// foreground is set correctly, nothing to do 
					} else if (((col[offset]&0x0f)==0x00)||((col[offset]&0x0f)==0x01)||((col[offset]&0x0f)==0x0e)) {
						// foreground is inverted, deal
						pat[offset] = ~pat[offset];
					} else {
						// probably no foreground, make sure
						if (pat[offset]!=0) printf("Warning, offset %d has no black and it has pixels set\n", offset);
					}
					col[offset]=0x17;	// black on cyan
				} else if (row == 4) {
					// this is an easy one, there's no pattern in here at all
					col[offset]=0x17;
					pat[offset]=0x00;
				} else if (row == 19) {
					// it's almost easy, but there's ONE pixel row of state in this row
					if (byte < 7) {
						// no pattern
						col[offset]=0x17;
						pat[offset]=0x00;
					} else {
						// the white part is the pattern
						if ((col[offset]&0xff)==0xff) {
							// solid, make sure pixels are set
							pat[offset] = 0xff;
						} else if ((col[offset]&0xf0)==0xf0) {
							// foreground is set correctly, nothing to do

						} else if ((col[offset]&0x0f)==0x0f) {
							// foreground is inverted, deal
							pat[offset] = ~pat[offset];
						} else {
							// probably no foreground, make sure
							if (pat[offset]!=0) printf("Warning, offset %d has no black and it has pixels set\n", offset);
						}
						col[offset]=0xf7;	// white on cyan
						}
				} else {
					// star or state area - white is important
					if ((col[offset]&0xff)==0xff) {
						// solid, make sure pattern is set
						pat[offset] = 0xff;
					} else if ((col[offset]&0xf0)==0xf0) {
						// foreground is set correctly, nothing to do

					} else if ((col[offset]&0x0f)==0x0f) {
						// foreground is inverted, deal
						pat[offset] = ~pat[offset];
					} else {
						// probably no foreground, make sure
						if (pat[offset]!=0) printf("Warning, offset %d has no black and it has pixels set\n", offset);
					}
					col[offset]=0xf7;	// white on cyan
				}
				++offset;
			}
		}
	}

	// write it back out for verification
	fp=fopen("C:\\WORK\\TI\\megademo\\ti99demo\\DONTMESS2.TIAC", "wb");
	if (6144+128 != fwrite(col, 1, 6144+128, fp)) {
		printf("failed to write color\n");
		return 1;
	}
	fclose(fp);
	fp=fopen("C:\\WORK\\TI\\megademo\\ti99demo\\DONTMESS2.TIAP", "wb");
	if (6144+128 != fwrite(pat, 1, 6144+128, fp)) {
		printf("failed to write pattern\n");
		return 1;
	}
	fclose(fp);

	// RLE encode the pattern table
	int outSize = 0;
	unsigned char *outbuf = RLEEncode(&pat[128], &outSize, 6144);
	fp=fopen("C:\\WORK\\TI\\megademo\\ti99demo\\dontmess2-tiap-rle.bin", "wb");
	if (outSize != fwrite(outbuf, 1, outSize, fp)) {
		printf("failed to write RLE pattern\n");
		return 1;
	}
	fclose(fp);
	free(outbuf);


	return 0;
}

