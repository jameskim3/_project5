#include <iostream>>

int visited[100];
int sum;
void combi(int s, int n, int cnt) {
	if (cnt == 10) {
		sum++;
		return;
	}
	for (int i = s; i < n; i++) {
		combi(i + 1, n, cnt + 1);
	}
}
int arr[1000][1000];
int combination(int n, int r) {
	// nCr = (n-1)C(r-1) + (n-1)C(r)
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
int main() {
	int ret = combination(30, 10);
	printf("Combi:%d", ret);
	return 0;
}