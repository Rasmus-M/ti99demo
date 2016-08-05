// Simple tool to RLE pack the end credits so we don't have to
// do it manually
// Input: <infile> <outfile>
// Looks for "SCRTXT" and TEXT declarations to pack
// output file replaces SCRTXT with BYTE statements representing
// a simple RLE code: high bit indicates repeated bytes (set) or inline data (clear),
// last 7 bits represent how many. Following byte or bytes are the data in question.
// This actually saves over a k! ;)

#include <stdio.h>
#include <string.h>

char txtbuf[16384];		// more than we'll need
unsigned char outbuf[4096];		// i hope more than we'll need! ;)
char linebuf[1024];

int main(int argc, char *argv[]) {
	FILE *fin, *fout;
	int inpos=0, outpos=0;
	char *c1,*c2;
	int chr = 0;
	int cnt = 0;
	int pos = 0;
	int idx;

	if (argc < 3) {
		printf("packcreds <infile> <outfile>\n");
		return 5;
	}

	fin = fopen(argv[1], "r");
	if (NULL == fin) {
		printf("Can't open input file: %s\n", argv[1]);
		return 5;
	}

	fout = fopen(argv[2], "w");
	if (NULL == fout) {
		printf("Can't open output file: %s\n", argv[2]);
		fclose(fin);
		return 5;
	}

	// copy lines until we get to SCRTXT
	while (!feof(fin)) {

		if (NULL == fgets(linebuf, sizeof(linebuf), fin)) {
			printf("Never found SCRTXT\n");
			// eof or error
			break;
		}

		if (0 == strncmp("SCRTXT", linebuf, 6)) {
			break;
		}

		fputs(linebuf, fout);
	}

	// was that the end?
	if (feof(fin)) {
		fclose(fin);
		fclose(fout);
		return 1;
	}

	// now we can start copying out the data
	// each row should be 32 characters embedded in single quotes
	// watch out for two single quotes side by side ('') (means one)
	while (strstr(linebuf, "TEXT")) {
		// we have a string to start with
		c1 = strchr(linebuf, '\'');
		if (NULL == c1) break;
		c2 = strchr(c1+1, '\'');
		if (NULL == c2) break;
		while (*(c2+1)=='\'') {
			c2 = strchr(c2+2, '\'');
			if (NULL == c2) break;
		}
		++c1;
		while (c1 < c2) {
			if ((*c1 == '\'')&&(*(c1+1)=='\'')) ++c1;
			txtbuf[inpos++]=*(c1++);
		}
		if (NULL == fgets(linebuf, sizeof(linebuf), fin)) break;
	}

	// we stopped either because of a syntax error or no more TEXT lines,
	// so before we go any further, RLE the txtbuf and output it as bytes
	// instead.
	chr = 0;
	cnt = 0;
	pos = 0;
	while (pos < inpos) {
		if (txtbuf[pos] == txtbuf[pos+1]) {
			// same byte
			chr = pos;
			cnt = 0;
			while ((txtbuf[chr] == txtbuf[pos++]) && (cnt<127) && (pos < inpos)) ++cnt;
			outbuf[outpos++] = cnt+0x80;
			outbuf[outpos++] = txtbuf[chr];
		} else {
			// string
			chr = outpos;
			cnt = 0;
			++outpos;
			while ((txtbuf[pos] != txtbuf[pos+1]) && (cnt<127) && (pos < inpos)) {
				outbuf[outpos++] = txtbuf[pos++];
			}
			outbuf[chr] = cnt;
		}
	}

	// now write the data
	pos = 0;
	fprintf(fout, "SCRTXT\n");
	while (pos < outpos) {
		fprintf(fout, "  BYTE ");
		for (idx=0; idx<16; idx++) {
			fprintf(fout, ">%02X", outbuf[pos++]);
			if (pos >= outpos) {
				fprintf(fout, "\n");
				break;
			}
			if (idx == 15) {
				fprintf(fout, "\n");
			} else {
				fprintf(fout, ",");
			}
		}
	}

	// now finish writing the output, starting with the line in the buffer
	fputs(linebuf, fout);

	while (!feof(fin)) {
		if (NULL == fgets(linebuf, sizeof(linebuf), fin)) break;
		fputs(linebuf, fout);
	}

	fclose(fin);
	fclose(fout);

	printf("Packed end credits from %d bytes to %d bytes\n", inpos, outpos);

	return 0;
}
