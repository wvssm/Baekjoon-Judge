#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n,m;
int board[510][510];
bool vis[510][510];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt, max_s;

void BFS(int x, int y) {
	queue<pair< int, int >> q;
	int size = 1;
	q.push({ x,y });
	vis[x][y] = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] != 1) continue;
			q.push({ nx,ny });
			vis[nx][ny] = 1;
			size++;
		}
	}

	if (max_s < size) max_s = size;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] && board[i][j]==1) {
				BFS(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << '\n' << max_s;
}