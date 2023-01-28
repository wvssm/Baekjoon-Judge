#include <bits/stdc++.h>
using namespace std;
int arr[2190][2190];

int m = 0;
int z = 0;
int p = 0;

void paper(int start_r, int end_r, int start_c, int end_c) {
	int same = 1;
	int before = arr[start_r][start_c];

	for (int i = start_r; i < end_r; i++) {
		for (int j = start_c; j < end_c; j++) {
			if (before != arr[i][j]) {
				same = 0;
				break;
			}
		}
	}
	// °°´Ù¸é
	if (same == 1) {
		if (before == -1) {
			m++;
		}
		else if (before == 0) z++;
		else if (before == 1) p++;
		return;
	}

	int length = (end_r - start_r) / 3;
	paper(start_r+0, start_r+length, start_c+0, start_c + length);
	paper(start_r + 0, start_r + length, start_c + length, start_c + length * 2);
	paper(start_r + 0, start_r + length, start_c + length * 2, start_c + length * 3);
	paper(start_r + length, start_r + length * 2, start_c + 0, start_c + length);
	paper(start_r + length, start_r + length * 2, start_c + length, start_c + length * 2);
	paper(start_r + length, start_r + length * 2, start_c + length * 2, start_c + length * 3);
	paper(start_r + length * 2, start_r + length * 3, start_c + 0, start_c + length);
	paper(start_r + length * 2, start_r + length * 3, start_c + length, start_c + length * 2);
	paper(start_r + length * 2, start_r + length * 3, start_c + length * 2, start_c + length * 3);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	paper(0, n, 0, n);
	cout << m << '\n' << z << '\n' << p << '\n';
}