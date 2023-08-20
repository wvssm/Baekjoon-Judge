// 백준 1182
// 백트래킹은 나뭇가지 형태의, 아래로 쭉 내려오는 형태를 가짐

#include <bits/stdc++.h>
using namespace std;
int n, s, cnt=0;
int arr[22];

void func(int cur, int sum) {
	// 미연시 퀘스트를 끝까지 했을 떼
	if (cur == n) {
		if (s == sum) {
			cnt++;
		}
		return;
	}

	// 미연시의 한 문제씩 푸는 것
	func(cur + 1, sum); // 원소를 선택안한 경우
	func(cur + 1, sum + arr[cur]); // 원소를 선택한 경우
} 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	func(0,0);
	if (s == 0) cout << cnt - 1; // 크기가 양수니까 공집합 제외 (이거때매 오답나옴)
	else cout << cnt;
}