#include <stdio.h>
#include<stdlib.h>
#include<time.h>

extern void test(unsigned char key[200]);

static int seed = 3;
static unsigned char dummy[512];
static unsigned char KEY[200];
static int pseudo_rand() {
	seed = seed * 214011 + 2531011;
	return (seed >> 16) & 0x7fff;
}

int check(unsigned char key[200]) {
	int pos = 0;
	int equal = 0;
	for (register int c = 0; c < 200; c++) {
		if (key[c] == KEY[c])pos++;

		for (register int c1 = 0; c1 < 200; c1++) {
			for (register int c2 = 0; c2 < 200; c2++) {
				if (key[c1] == KEY[c2])equal++;
			}
		}
	}
	return pos * 256 + equal;
}

int main() {
	int RESULT = 0;
	for (int t = 0; t < 50; t++) {
		unsigned char pool[255] = { 0 };
		for (register int c = 0; c < 200; c++) {
			int i = pseudo_rand() % 255;
			while (pool[i] == 1)i = pseudo_rand() % 255;
			KEY[c] = i + 1;
			pool[i] = 1;
		}
		unsigned char key[200] = { 0 };
		time_t start = clock();
		test(key);
		RESULT += (int)(clock() - start) / (CLOCKS_PER_SEC / 1000);
		for (register int c = 0; c < 200; c++) {
			if (key[c] != KEY[c])RESULT += 10000;
		}
	}
	printf("RESULT:%d", RESULT);
	return 0;
}
