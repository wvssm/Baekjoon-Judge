#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[1001];
int dist[1001][1001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;

void bfs(int x, int y) {
	queue<pair<int, int>>Q;
	dist[x][y] = 1;
	Q.push({ x,y });
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (dist[nx][ny] >= 1 || board[nx][ny] == '1')continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}
}

void masking(int n, int m) {
	for (int i = 0; i < n; i++) {
		fill(dist[i], dist[i] + m, 0);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	int mn = 100;
	bfs(0, 0); // 벽 아예 안뚫었을 때
	if (dist[n - 1][m - 1] != 0) mn = min(mn, dist[n - 1][m - 1]);
	masking(n, m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '1') {
				board[i][j] = '0'; 
				bfs(0, 0); // 벽 뚫었을 때
				if (dist[n-1][m-1] != 0) mn = min(mn, dist[n-1][m-1]);
				masking(n, m);
				board[i][j] = '1';
			}
		}
	}

	if (mn == 100) cout << -1;
	else cout << mn;
}

// push를 안함 