// 바킹독님 코드 보고 다듬은 코드
// https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x0B/solutions/1780.cpp

#include <bits/stdc++.h>
using namespace std;

int N;
int arr[2200][2200];
int cnt[3]; // -1, 0, 1로 채워진 종이의 개수

// 해당 종이 내부에 같은 숫자로만 채워졌는지 확인하는 함수
bool check(int r, int c, int n) {
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (arr[r][c] != arr[i][j]) { // 어차피 (r,c)가 첫 원소니까 다음과 같이 조건문 세우기
				return false;
			}
		}
	}
	return true;
}

void solve(int r, int c, int l) {
	// base condition: 모든 같은 수로 이루어져 있으면 수 세고 종료
	if (check(r, c, l)) {
		cnt[arr[r][c] + 1] += 1;
		return;
	}

	int n = l / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(r+i*n, c+j*n, n); // 들어가는 식 생각하면서 인수 작성하기
			// 그리고 자기 자신을 호출해야 재귀이지 다른 함수 부르면 안됨
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	solve(0, 0, N);
	for (int i = 0; i < 3; i++) cout << cnt[i] << '\n';
}