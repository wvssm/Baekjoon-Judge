// 백준 1182 - 부분수열의 합, 솔루션
#include <bits/stdc++.h>
using namespace std;

int n, s;
int cnt = 0; // 숫자 초기화해주기
int arr[30];

void func(int cur, int tot) {
	if (cur == n) {
		if (tot == s) {
			cnt++;
		}
		return; // 탈출구의 위치 중요
	}

	// 포함 안포함을 어떻게 표현해야 할지 감이 안잡혔음
	func(cur + 1, tot); // 부분집합에 원소를 포함하지 않는 경우
	func(cur + 1, tot + arr[cur]); // 부분집합에 원소를 포함하는 경우
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	func(0, 0);
	if (s == 0) cnt--; // 공집합인 경우 빼기
	cout << cnt;
}