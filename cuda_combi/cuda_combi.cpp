// cuda_combi.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

int N;
int arr[1000][1000];
int ret[1000][30];

int  combi(int n, int r) {
	if (n == r || r == 0) {
		return 1;
	}
	return combi(n - 1, r - 1) + combi(n - 1, r);
}

int combi2(int n, int r) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= r; j++) {
			if (i == j || j == 0)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	return arr[n][r];
}
int main()
{
	int n = 5;
	int r = 2;
	printf("Result1 %dC%d is %d\n", n, r, combi(n, r));
	printf("Result2 %dC%d is %d\n", n, r, combi2(n, r));
}
/*
								C(5, 2)
                    /                      \
           C(4, 1)                           C(4, 2)
            /   \                          /           \
       C(3, 0)   C(3, 1)             C(3, 1)               C(3, 2)
                /    \               /     \               /     \
         C(2, 0)    C(2, 1)      C(2, 0) C(2, 1)          C(2, 1)  C(2, 2)
                   /        \              /   \            /    \
               C(1, 0)  C(1, 1)      C(1, 0)  C(1, 1)   C(1, 0)  C(1, 1)
*/
