#include <iostream>

using namespace std;
#define ALPHA
//data
#ifdef ALPHA 
const int alpha[10][8][8] =
{
	{ //0
		{ 0, 0, 0, 0, 8, 8, 8, 8 },
		{ 0, 0, 0, 0, 8, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
	},

	{ //1
		{ 0, 0, 0, 0, 8, 8, 8, 8 },
		{ 0, 0, 0, 0, 8, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 0, 0, 0 },
	},

	{ //2
		{ 0, 0, 0, 0, 8, 8, 8, 8 },
		{ 0, 0, 0, 0, 8, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 8, 8, 8 },
	},

	{ //3
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 0, 0, 0 },
		{ 0, 0, 0, 0, 8, 8, 8, 8 },
	},

	{ //4
		{ 8, 8, 8, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
	},

	{ //5
		{ 8, 8, 8, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 8, 0, 0, 0, 0 },
	},

	{ //6
		{ 8, 8, 8, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 8, 0, 0, 0, 0 },
		{ 8, 8, 8, 8, 0, 0, 0, 0 },
	},
	{ //7
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 8, 0, 0, 0, 0 },
		{ 0, 0, 0, 8, 0, 0, 0, 0 },
		{ 8, 8, 8, 8, 0, 0, 0, 0 },
	},
	{ //8
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 8, 0, 0, 8, 0, 0 },
		{ 0, 0, 8, 0, 0, 8, 0, 0 },
		{ 0, 0, 8, 0, 0, 8, 0, 0 },
		{ 0, 0, 8, 8, 8, 8, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
	},
	{ //9
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 8, 8, 8, 8, 0, 0 },
		{ 0, 0, 8, 0, 0, 8, 0, 0 },
		{ 0, 0, 8, 0, 0, 8, 0, 0 },
		{ 0, 0, 8, 0, 0, 8, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
	},
};
#endif

static int dummy1[12];
static char photo[16][64];
static int dummy2[34];
static int seed;
static int dummy3[56];
static void bitblt(int bx, int by, int n){
	for (int y = 0; y < 8; y++){
		for (int x = 0; x < 8; x++){
			photo[by + y][bx + x] = alpha[n][y][x];
		}
	}
}
static int pseudo_rand(){
	seed = seed * 214013 + 2531011;
	return (seed >> 16) & 0x7fff;
}
extern int recog(char photo[16][64]);
static void shot(int n){
	for (int y = 0; y < 16; y++){
		for (int x = 0; x < 64; x++){
			photo[y][x] = 0;
		}
	}

	int cursor = 0;
	int pos = 1000;

	for (int c = 0; c < 4; c++){
		cursor += pseudo_rand() % 9;
		int bx = cursor;
		int by = pseudo_rand() % 9;
		int N = (n / pos) % 10;

		for (int y = 0; y < 8; y++){
			for (int x = 0; x < 8; x++){
				photo[by + y][bx + x] = alpha[N][y][x];
			}
		}
		cursor += 8;
		pos /= 10;
	}
	for (int y = 0; y < 16; y++){
		for (int x = 0; x < 64; x++){
			if (pseudo_rand() % 10 == 0){
				photo[y][x] = (photo[y][x] == 0) ? 8 : 0;
			}
		}
	}
}

int main(){
	seed = 3;
	int RESULT = 0;
	for (int c = 0; c < 2000; c++){
		int number = pseudo_rand() % 10000;
		shot(number);

		if (recog(photo) == number)
			RESULT++;
	}
	printf("RESULT:%d\n", RESULT);
	return 0;
}
			












/*
int capture[16][64];

extern int userCode(int arr[16][64]);
void assign(int digit, int bx, int by)
{
	for (int y = 0; y < 8; y++)
	for (int x = 0; x < 8; x++)
	{
		capture[by + y][bx + x] = alpha[digit][y][x];
	}
}
int main()
{
	int score = 0;
	for (int i = 0; i < 2000; i++)
	{
		int digit = rand() % 10000;
		for (int y = 0; y < 16; y++)
		for (int x = 0; x < 64; x++)
			capture[y][x] = 0;

		int number = rand() % 10000;
		int number_origin = number;
		int devide = 1000;
		int by = 0;
		int bx = 0;
		for (int c = 0; c < 4; c++)
		{
			int digit = number / devide;
			bx += rand() % 9;
			by = rand() % 9;
			assign(digit, bx, by);

			number -= digit*devide;
			devide /= 10;
			bx += 8;
		}

		if (userCode(capture) == number_origin)
			score++;
	}
	printf("Score:%d\n");
}
*/