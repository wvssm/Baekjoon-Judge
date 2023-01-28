// ��ŷ���� �ڵ� ���� �ٵ��� �ڵ�
// https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x0B/solutions/1780.cpp

#include <bits/stdc++.h>
using namespace std;

int N;
int arr[2200][2200];
int cnt[3]; // -1, 0, 1�� ä���� ������ ����

// �ش� ���� ���ο� ���� ���ڷθ� ä�������� Ȯ���ϴ� �Լ�
bool check(int r, int c, int n) {
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (arr[r][c] != arr[i][j]) { // ������ (r,c)�� ù ���Ҵϱ� ������ ���� ���ǹ� �����
				return false;
			}
		}
	}
	return true;
}

void solve(int r, int c, int l) {
	// base condition: ��� ���� ���� �̷���� ������ �� ���� ����
	if (check(r, c, l)) {
		cnt[arr[r][c] + 1] += 1;
		return;
	}

	int n = l / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(r+i*n, c+j*n, n); // ���� �� �����ϸ鼭 �μ� �ۼ��ϱ�
			// �׸��� �ڱ� �ڽ��� ȣ���ؾ� ������� �ٸ� �Լ� �θ��� �ȵ�
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