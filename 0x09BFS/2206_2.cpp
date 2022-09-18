// 답보고 구현할 수 있는지 다시한번 연습
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[1001];
int dist[1001][1001][2];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;

int OOB(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return 1;
	else return 0;
}

int bfs(int x, int y) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j][0] = dist[i][j][1] = -1;
		}
	}
	dist[0][0][0] = dist[0][0][1] = 1;
	queue < tuple<int, int, int>>Q;
	int broke = 0;
	Q.push({ 0,0,0});
	while (!Q.empty()) {
		int x, y, broke;
		tie(x, y, broke) = Q.front(); Q.pop();
		if (x == n-1 && y == m-1) return dist[x][y][broke];
		int nextdist = dist[x][y][broke] + 1;
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (OOB(nx,ny)) continue;
			if (board[nx][ny] == '0' && dist[nx][ny][broke] == -1) {
				dist[nx][ny][broke] = nextdist;
				Q.push({ nx,ny,broke });
			}

			if (!broke && board[nx][ny] == '1' && dist[nx][ny][1] == -1) { // 벽일때는 벽뚫고 지나갔다고 broke 대신 1을 써주면 된다
				//broke = -1; 
				dist[nx][ny][1] = nextdist;//dist[nx][ny][broke] = nextdist;
				Q.push({ nx,ny,1}); //Q.push({ nx,ny,broke });
			}
		}
	}
	return -1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	int ans = bfs(0, 0);

	cout << ans;
	return 0;
}


// 최종목적지 (x==n-1 && y==m-1)이다 (x==n&&y==m)아니다