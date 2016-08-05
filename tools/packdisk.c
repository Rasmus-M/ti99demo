// Simple tool to pack all the demo files together with a small directory
// at the beginning. All files are 128-byte aligned so we can read them
// with the record function
// Index is two bytes of offset and two bytes of length
// First two records are index (allows room for 64 files)
// remaining sectors are data.

#include <stdio.h>

FILE *fout, *fin;
unsigned char index[256];
int outpos, idx, pos;

// pass in the output file followed by the files to add
int main(int argc, char *argv[]) {
	if (argc<3) {
		printf("packdisk <output file> <one or more input files>\n");
		return 5;
	}

	fout = fopen(argv[1], "wb+");
	if (NULL == fout) {
		printf("Can't open output file\n");
		return 1;
	}

	// make room for the index
	fwrite(index, 256, 1, fout);
	outpos = 0;

	// now loop through and add all the files
	for (idx=2; idx<argc; idx++) {
		// align to 256 bytes
		while (ftell(fout)%256) fputc(0, fout);
		
		// update the index
		pos = ftell(fout) / 128;			// get as records
		index[outpos] = (pos/256)&0xff;		// high byte of start
		index[outpos+1]=(pos&0xff);			// low byte of start
		outpos+=2;

		// now copy in the file
		fin = fopen(argv[idx], "rb");
		if (NULL == fin) {
			printf("Failed reading input file '%s'\n", argv[idx]);
			break;
		}

		while (!feof(fin)) {
			fputc(fgetc(fin), fout);
		}

		// update the index
		fseek(fin, 0, SEEK_END);
		pos = ftell(fin) / 128;
		index[outpos] = (pos/256)&0xff;		// high byte of length
		index[outpos+1]=(pos&0xff);			// low byte of length
		outpos+=2;

		fclose(fin);
	}

	// now write the index sector
	fseek(fout, 0, SEEK_SET);
	fwrite(index, 256, 1, fout);

	// and save out the file
	fclose(fout);

	return 0;
}

