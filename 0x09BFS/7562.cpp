#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dist[301][301];
int dx[8] = {2,2,1,1,-1,-1,-2,-2};
int dy[8] = { 1,-1,2,-2,2,-2,1,-1 };
int t, n, sx, sy, ex, ey;

void masking(int n) {
	for (int i = 0; i < n; i++) {
		fill(dist[i], dist[i] + n, -1);
	}
}

void bfs(int i, int j) {
	queue<pair<int, int>>Q;
	dist[i][j] = 0;
	Q.push({ i,j });
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 8; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			if (nx == ex && ny == ey) break;
			Q.push({ nx,ny });
		} 
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		masking(n);
		cin >> sx >> sy;
		cin >> ex >> ey;
		bfs(sx, sy);
		cout << dist[ex][ey] << '\n';
	}
}
/*
단순 거리 구하기 문제, 
단 상하좌우 이동이 아니라 8방향 이동일 뿐

디버깅: dx[i]가 아니라 dx[dir]넣어야 하는데 잘못함
*/