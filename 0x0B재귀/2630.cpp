// 1780과 숫자만 다르고 똑같은 문제
#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[2];
int paper[130][130];

bool check(int r, int c, int n) {
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (paper[r][c] != paper[i][j]) return false;
		}
	}
	return true;
}

void solve(int r, int c, int n) {
	// base condition
	if (check(r, c, n)) {
		cnt[paper[r][c]] += 1;
		return;
	}

	int l = n / 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			solve(r + l * i, c + l * j,l);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}
	solve(0, 0, n);
	cout << cnt[0] << '\n' << cnt[1];
}