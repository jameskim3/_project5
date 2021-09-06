#define ALPHA2
#ifdef ALPHA2
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
typedef struct{
	int num, val;
}DP;
DP dp[72][5];
int xx[64];
int yy[64];
int W, R;
int M, MAX, NUM;
int ccnt;
char myphoto[16][64];

void check(int x){
	int i, k, w, h;
	if (xx[x] != -1){
		R = xx[x];
		M = yy[x];
		return;
	}
	double cnt, min = -10000;
	for (i = 0; i < 9; i++){
		for (k = 0; k < 10; k++){
			cnt = 1;
			for (h = 0; h < 8; h++){
				for (w = 0; w < 8; w++){
					if (alpha[k][h][w] == 0)continue;
					if (myphoto[i + h][x + w] == alpha[k][h][w]){
						cnt += 1;
					}
					else{
						cnt -= 1;
					}
				}
			}
			if (cnt > min){
				M = min = cnt;
				R = k;
				W = x;
			}
		}
	}
	xx[x] = R;
	yy[x] = M;
	return;
}

DP dfs(int n, int x){
	DP result;
	DP temp;
	result.val = -11111;
	result.num = 0;
	if (dp[x][n].val > -11111)
		return dp[x][n];
	if (n == 0){
		result.val = -11111;
		result.num = 0;
		return result;
	}
	if (x >= 64)
		return result;

	int i, r, j, m;
	int ten = 1;
	for (j = 2; j <= n; j++){
		ten *= 10;
	}
	for (i = 0; i <= 8; i++){
		check(x + i);
		r = R*ten;
		m = M;
		temp = dfs(n - 1, x + i + 8);
		temp.val += m;
		temp.num += r;
		if (temp.val > result.val){
			result = temp;
		}
	}
	dp[x][n] = result;
	return dp[x][n];
}

int recog(char photo[16][64]){
	int i, j, w = 0, r = 0;
	for (i = 0; i < 16; i++){
		for (j = 0; j < 64; j++){
			myphoto[i][j] = photo[i][j];
		}
	}
	for (i = 0; i < 72; i++){
		for (j = 0; j < 5; j++){
			dp[i][j].val = -11111;
		}
	}
	for (i = 0; i < 64; i++){
		xx[i] = -1;
	}
	DP result = dfs(4, 0);
	i = 1;
	return result.num;
}
