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

// 보드판을 입력받는 함수
void input() {
	cin >> m >> n; // 입력을 n,m(행열) 순서가 아니라 m,n 순서로 받아야 함
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
}

// BFS를 수행하는 함수
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

// 안익은 토마토가 있는지 확인하는 함수
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
	// 보드판 입력 받기
	input(); 
	// 시작점(익은토마토) 큐에 넣기
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && vis[i][j] == 0) {
				Q.push({ i,j });
				vis[i][j] = 1;
			}
		}
	}
	// BFS 수행하기
	BFS();
	// 토마토가 다 익은지 확인하기
	if (isFalse()) cout << -1;
	else { // 토마토가 다 익었으면 vis배열을 돌아 제일 늦게 익은 토마토 날짜 구하기
		int maxVal = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				maxVal = max(vis[i][j], maxVal);
			}
		}
		cout << maxVal - 1; // 이미 익은 첫재날을 빼야 답이 맞음
	}
}
/*
★시작점이 여러개인 BFS -> 모든 시작점을 Queue에 넣고 시작하면 된다!

디버깅:
1) 입력을 n,m(행열) 순서가 아니라 m,n 순서로 받아야 함
2) 배열에서 최대값 구하는 형식 외우기
for문{
mx = max (mx, a[i][j]);
}
*/