#include <stdio.h>
#include<time.h>

extern void mygputest();
int main()
{
	time_t start = clock();
	mygputest();
	printf("Perfomance is %d\n", clock() - start);
	return 0;
}

/*

const int N = 20;
const int K = 10;
typedef struct cm {
	int sum, val, pre;
}CM;

typedef struct list {
	int cnt;
	int arr[200000];
}LIST;
CM map[62000000];
LIST ret[N + 10][K + 10];
int wp;
int totla_cnt;
int combi(int n, int k) {
	CM* p = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k && j <= i; j++) {
			int cnt = 0;
			if (j == 0) {
				map[wp].pre = 0;
				map[wp].val = -1;
				map[wp].sum = 0;
				ret[i][j].arr[cnt++] = wp++;
				ret[i][j].cnt++;
			}
			else if (j == i) {
				map[wp].pre = ret[i - 1][j - 1].arr[0];
				map[wp].val = i;
				p = &map[ret[i - 1][j - 1].arr[0]];
				map[wp].sum = p->sum + i;
				ret[i][j].arr[cnt++] = wp++;
				ret[i][j].cnt++;
			}
			else {
				int cnt = 0;
				int rep = 0;
				while (rep < ret[i - 1][j - 1].cnt) {
					map[wp].pre = ret[i - 1][j - 1].arr[rep];
					map[wp].val = i;
					p = &map[ret[i - 1][j - 1].arr[rep]];
					map[wp].sum = p->sum + i;
					ret[i][j].arr[cnt] = wp++;
					cnt++;
					rep++;
					ret[i][j].cnt++;
				}
				rep = 0;
				while (rep < ret[i - 1][j].cnt) {
					map[wp].pre = ret[i - 1][j].arr[rep];
					map[wp].val = -1;
					map[wp].sum = p->sum;
					ret[i][j].arr[cnt] = wp++;
					cnt++; rep++;
					ret[i][j].cnt++;
				}
			}
		}
	}
	return ret[n][k].cnt;
}
*/