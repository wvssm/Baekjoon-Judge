// 토마토가 여러개일 때를 생각안하고 코드를 짰다.
// bfs의 특성을 살리지 못함
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m, sum; 
int board[1002][1002];
int vis[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


void check(int x, int y) {
	int max_vis = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//cout << vis[i][j] << ' ';
			if (vis[i][j] == 0 && board[i][j]!=-1) {
				cout << -1;
				return;
			}

			if (max_vis < vis[i][j]) {
				max_vis = vis[i][j];
			}
		}
		//cout << '\n';
	}
	cout << max_vis-1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> q;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j]==1 && vis[i][j]==0 ) {
				q.push({ i,j });
				vis[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] < 0) continue;

			vis[nx][ny] = vis[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
		}
	}

	check(0, 0);
}