// 백준 15655 N과 M(6)
#include <bits/stdc++.h>
using namespace std;

int n, m, st;
int arr[10];
int input[10];
int isused[10];

void func(int cur, int index) {
	if (cur == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// 이전에 조합 푼 것 처럼 for문 시작점 정해주기
	st = 0;
	if (cur != 0) st = index+1;
	
	for (int i = st; i < n; i++) {
		if (!isused[i]) {
			arr[cur] = input[i];
			isused[i] = 1;
			func(cur + 1, i);
			isused[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input, input + n);
	func(0,0);
}