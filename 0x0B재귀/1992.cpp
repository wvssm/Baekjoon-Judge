/*
* [����] 1992 ����Ʈ��
* 1780, 2630�� �ذ��� ����
* 
* <������>
* ����� �ణ ��ٷο�
* ���� ���� �پ��ִ� ���� �Է¹ޱ�
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
		// ���� ��� ���
		cout << video[r][c];
		return;
	}

	int h = n / 2;
	
	// ���� ������ ���� ��ȣ�� ������
	cout << "(";
	solve(r, c, h); // ���� ��
	solve(r, c+h, h); // ������ ��
	solve(r+h, c, h); // ���� �Ʒ�
	solve(r+h, c+h, h); // ������ �Ʒ�
	cout << ")";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	// ���ڿ��� �پ��ִ� ���� ó���ϴ� ��
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			video[i][j] = str[j] - '0';
		}
	}
	solve(0, 0, N);
}