// 백준 1182 - 부분수열의 합
// 내가 작성하다가 실패한 코드
#include <bits/stdc++.h>
using namespace std;

int n, s, cnt;
int num[22];
int isused[44];
int isused2[44];
int sum;

void solve(int k) {
	if (k == n) {
		if (sum == s) {
			cnt++;
			return;
		}
	}

	for (int i = 0; i <2; i++) {
		if (i % 2 != 0) sum += num[k];
		else sum += 0;

		solve(k + 1);
		sum = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	solve(0);
	cout << cnt;
}