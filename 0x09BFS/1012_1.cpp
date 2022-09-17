#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[51][51];
bool vis[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, k;
queue < pair<int, int>>q;

void bfs(int x, int y) {
	vis[x][y] = 1;
	q.push({ x,y });
	while (!q.empty()) {
		pair<int, int>cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] != 0 || board[nx][ny] != 1) continue;
			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		int x, y;
		while (k--) {
			cin >> y >> x;
			board[x][y] = 1;
		}
		int res = 0; //지렁이 개수
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1 && vis[i][j] == 0) {
					bfs(i, j);
					res++;
				}
			}
		}
		cout << res << '\n';
		for (int i = 0; i < n; i++) {
			fill(board[i], board[i] + 51, 0);
			fill(vis[i], vis[i] + 51, 0);
		}
	}
	return 0;
}