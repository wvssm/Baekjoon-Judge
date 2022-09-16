#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[1002][1002];
int vis[1002][1002];
int n, m, day;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>>Q;

// �������� �Է¹޴� �Լ�
void input() {
	cin >> m >> n; // �Է��� n,m(�࿭) ������ �ƴ϶� m,n ������ �޾ƾ� ��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
}

// BFS�� �����ϴ� �Լ�
void BFS() {
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] >= 1 || board[nx][ny] != 0) continue;
			vis[nx][ny] = vis[cur.X][cur.Y] + 1;
			board[nx][ny] = 1;
			Q.push({ nx,ny });
		}
	}
}

// ������ �丶�䰡 �ִ��� Ȯ���ϴ� �Լ�
int isFalse() { 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// ������ �Է� �ޱ�
	input(); 
	// ������(�����丶��) ť�� �ֱ�
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && vis[i][j] == 0) {
				Q.push({ i,j });
				vis[i][j] = 1;
			}
		}
	}
	// BFS �����ϱ�
	BFS();
	// �丶�䰡 �� ������ Ȯ���ϱ�
	if (isFalse()) cout << -1;
	else { // �丶�䰡 �� �;����� vis�迭�� ���� ���� �ʰ� ���� �丶�� ��¥ ���ϱ�
		int maxVal = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				maxVal = max(vis[i][j], maxVal);
			}
		}
		cout << maxVal - 1; // �̹� ���� ù�糯�� ���� ���� ����
	}
}
/*
�ڽ������� �������� BFS -> ��� �������� Queue�� �ְ� �����ϸ� �ȴ�!

�����:
1) �Է��� n,m(�࿭) ������ �ƴ϶� m,n ������ �޾ƾ� ��
2) �迭���� �ִ밪 ���ϴ� ���� �ܿ��
for��{
mx = max (mx, a[i][j]);
}
*/