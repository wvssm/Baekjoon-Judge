#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[301][301];
int minu[301][301];
int vis[301][301];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, year=0;

// 시간복잡도 O(NM)
void count_melt(int x, int y) {
	queue<pair<int, int>> q;
	vis[x][y] = year;
	q.push({ x,y });
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			//cout << "nx: " << nx << ' ' << ny << '\n';
			if (board[nx][ny] == 0) minu[cur.X][cur.Y] += 1; // 주변에 0의 개수 저장
			if (x < 0 || x >= n || y < 0 || y >= m)  continue;
			if (vis[nx][ny] != year - 1 || board[nx][ny] == 0) continue;
			vis[nx][ny] = year;
			q.push({ nx, ny });
		}
	}
}

// 시간복잡도 O(NM)
void melt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			board[i][j] = board[i][j] - minu[i][j];
			minu[i][j] = 0; // 다시 초기화 (이거 안해서 틀림)
			if (board[i][j] < 0) board[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// 입력 받기
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	// 방문 -1로 초기화
	for (int i = 0; i < n; i++) {
		fill(vis[i], vis[i] + m + 1, -1);
	}

	int part = 0; // 덩어리 개수
	int isZero = 0; // 빙산이 다 녹았는지 확인

	while (part != 2) {
		part = 0;
		isZero = 1; 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] != 0 && vis[i][j] == year - 1) { 
					isZero = 0;
					part++; // 덩어리 개수 증가
					if (part == 2) {
						cout << year; // 덩어리가 두개 이상인 경우
						return 0;
					}
					count_melt(i, j); // 녹일 높이 세기
				}
			}
		}
		if (isZero) {
			cout << 0; // 다 녹은 경우
			return 0;
		}
		melt(); // 녹이기
		year++;
	}
}

// 시간복잡도: O((2+year)*N*M) = O(NM * year)
// 공간복잡도: O(3*N*M+13) = O(3NM)
// 80ms