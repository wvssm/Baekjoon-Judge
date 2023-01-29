/*
* [백준] 1992 쿼드트리
* 1780, 2630과 해결방식 같음
* 
* <차이점>
* 출력이 약간 까다로움
* 공백 없이 붙어있는 숫자 입력받기
*/

#include <bits/stdc++.h>
using namespace std;

int N;
int video[70][70];

bool check(int r, int c, int n) {
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (video[r][c] != video[i][j]) return false;
		}
	}
	return true;
}

void solve(int r, int c, int n) {
	if (n==1 || check(r, c, n)) {
		// 압축 결과 출력
		cout << video[r][c];
		return;
	}

	int h = n / 2;
	
	// 압축 실패한 것은 괄호로 묶어줌
	cout << "(";
	solve(r, c, h); // 왼쪽 위
	solve(r, c+h, h); // 오른쪽 위
	solve(r+h, c, h); // 왼쪽 아래
	solve(r+h, c+h, h); // 오른쪽 아래
	cout << ")";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	// 문자열로 붙어있는 숫자 처리하는 법
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			video[i][j] = str[j] - '0';
		}
	}
	solve(0, 0, N);
}