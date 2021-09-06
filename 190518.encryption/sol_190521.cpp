int check(unsigned char key[200]);
int Wp, count[7] = { 1,2,4,8,16,32,64 };
unsigned char temp[200], candidate[7], number[200], *KEY;

int query(int s, int e, unsigned char left, unsigned char right) {
	int m = (s + e) / 2;
	for (register int i = 0; i < 200; i++) {
		if (i >= s && i <= m)
			temp[i] = left;
		else if (i >= m + 1 && i <= e)
			temp[i] = right;
		else
			temp[i] = 0;
	}
	int strike = check(temp) / 256;
	return strike;
}

void divide(int s, int e, unsigned char data[200], int dataCnt) {
	if (s == e) {
		KEY[s] = data[0];
		return;
	}
	int m = (s + e) / 2;

	unsigned char grpLeft[100], grpRight[100];
	register int lwp = 0;
	register int rwp = 0;
	register int i, j, k;

	for (i = 0; i < dataCnt;) {
		if (m - s + 1 == lwp) {
			for (k = i; k < dataCnt; k++)
				grpRight[rwp++] = data[k];
			break;
		}
		else if (dataCnt / 2 == rwp) {
			for (k = i; k < dataCnt; k++)
				grpLeft[lwp++] = data[k];
			break;
		}

		int left = data[i];

		for (j = i + 1; j < dataCnt; j++) {
			int right = data[j];
			int strike = query(s, e, left, right);
			if (strike == 2) {
				for (k = i + 1; k < j; k++)
					grpLeft[lwp++] = data[k];
				grpLeft[lwp++] = left;
				grpRight[rwp++] = right;
				i = j + 1;
				break;
			}
			else if (strike == 0) {
				for (k = i + 1; k < j; k++)
					grpRight[rwp++] = data[k];
				grpLeft[lwp++] = right;
				grpRight[rwp++] = left;
				i = j + 1;
				break;
			}
		}
	}
	divide(s, m, grpLeft, lwp);
	divide(m + 1, e, grpRight, rwp);
}

void test(unsigned char key[200]) {
	KEY = key;
	int k = 1;
	Wp = 0;
	for (int i = 0; i < 200; i++) {
		key[i] = temp[i] = 0;
	}
	while (Wp < 200) {
		int wp = 0;
		register int c;
		for (c = 0; c < 7 && k <= 255; c++) {
			candidate[c] = k++;
		}
		for (register int i = 0; i < c; i++) {
			for (int j = 0; j < count[i]; j++) {
				temp[wp++] = candidate[i];
			}
		}
		int ballCount = check(temp) % 256;
		for (register int i = 0; i < c; i++) {
			if ((ballCount&count[i]) == count[i]) {
				number[Wp++] = candidate[i];
			}
		}
		divide(0, 199, number, 200);
	}
}
