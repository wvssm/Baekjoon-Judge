// Authored by : seeys
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/99a676d859f54fa0944f81f94ade04a3
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[101];
bool vis[101][101];
int n;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int i, int j) {
	queue<pair<int, int>> Q;
	Q.push({ i,j });
	vis[i][j] = 1;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (vis[nx][ny] != 0 || board[nx][ny] != board[cur.X][cur.Y]) continue;
			vis[nx][ny]=1;
			Q.push({ nx,ny });
		}
	}
}

int area() {
	int cnt=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!vis[i][j]) {
				bfs(i,j);
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	// input
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	int not_g = area(); // ���ϻ����� �ƴ� ���

	// ���ϻ����� ����� ���� ������ ���� ���ϱ� ���� �湮�迭 �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		fill(vis[i], vis[i] + n, 0);
	}

	// ���ϻ����� �ʷϰ� ������ ���� ���ϹǷ� �ʷ��̸� �������� �ٲ���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'G') board[i][j] = 'R';
		}
	}

	int is_g = area(); // ���ϻ����� ���
	cout << not_g << " " << is_g;
	return 0;
}
/*
���� BFS�� ��������(R, G, B),
BFS ������ ���� board���� ���� ���� �ܴ�.
�״��� �˾��� ���� ����� R,G�� ���и��ϱ� ������ G�� ��� R�� �س��� ���� �ٽ� BFS�� ������.
area �Լ��� ������ ������ return �ϴ� �Լ���.
*/