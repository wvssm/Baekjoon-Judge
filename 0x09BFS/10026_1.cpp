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

	int not_g = area(); // 적록색약이 아닌 사람

	// 적록색약인 사람이 보는 구간의 수를 구하기 위한 방문배열 초기화
	for (int i = 0; i < n; i++) {
		fill(vis[i], vis[i] + n, 0);
	}

	// 적록색약은 초록과 빨강을 구분 못하므로 초록이면 빨강으로 바꿔줌
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'G') board[i][j] = 'R';
		}
	}

	int is_g = area(); // 적록색약인 사람
	cout << not_g << " " << is_g;
	return 0;
}
/*
각자 BFS를 돌린다음(R, G, B),
BFS 조건을 이전 board모양과 같은 경우로 단다.
그다음 알약을 먹은 사람은 R,G를 구분못하기 때문에 G를 모두 R로 해놓은 다음 다시 BFS를 돌린다.
area 함수는 나눠진 구역을 return 하는 함수다.
*/