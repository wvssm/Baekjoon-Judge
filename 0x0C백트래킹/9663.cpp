//// 백준 9663 - N-Queen
#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
int isused_1[30], isused_2[30], isused_3[30]; // 이 배열을 만들어서 쓰였는지 바로 확인하는 것이 핵심

void solve(int cur) {
	if (cur == n) { // n개의 행 모두다 말을 배치 시켰으면
		cnt++; // 수 증가
		return; // 종료
	}

	for (int i = 0; i < n; i++) {
		if (isused_1[i]) continue; // 열 검사
		else if (isused_2[cur + i]) continue; // 상향 대각선 검사
		else if (isused_3[cur - i + n - 1]) continue; // 하향 대각선 검사
		isused_1[i] = 1;
		isused_2[cur + i] = 1;
		isused_3[cur - i + n - 1] = 1;
		solve(cur + 1); // 다음 행에 놓을 말의 열의 위치 정하기
		isused_1[i] = 0;
		isused_2[cur + i] = 0;
		isused_3[cur - i + n - 1] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	solve(0);
	cout << cnt;
}