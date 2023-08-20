#include <bits/stdc++.h>

using namespace std;

int n;
int cnt=0;

// 순회를 하지말고 지금 위치에 있는지 확인
int isUsedCol[20];
int isUsed_1[40]; // DiagonalMinus
int isUsed_2[40]; //DiagonalPlus

void func(int cur) {
	// 미연시 모든 문제 해결
	if (cur == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isUsedCol[i] || isUsed_1[n - 1 + cur - i] || isUsed_2[cur + i]) continue;
		isUsedCol[i] = 1;
		isUsed_1[n - 1 + cur - i] = 1;
		isUsed_2[cur + i] = 1;
		func(cur + 1);
		isUsedCol[i] = 0; // 초기화하고 다음 경우 실행
		isUsed_1[n - 1 + cur - i] = 0;
		isUsed_2[cur + i] = 0;
	}
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	func(0);
	cout << cnt;
}