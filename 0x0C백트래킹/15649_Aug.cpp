// 백준 15649번 백트래킹 복습
#include <bits/stdc++.h>
using namespace std;

int m, n;
int arr[10];
int isused[10];

void func(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// cur번째 숫자 고르기
	for (int i = 1; i <= n; i++) {
		if (!isused[i]) {
			arr[cur] = i; 
			isused[i] = 1;
			func(cur + 1);
			isused[i] = 0; // 모든 경우 돌기 위해 돌아옴
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);
}