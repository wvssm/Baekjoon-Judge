#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[52][52];
bool vist[52][52];
int n, m,k;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		int x, y;
		int cnt=0;
		//보드판 채우기
		while (k--) {
			cin >> y >> x;
			board[x][y] = 1;
		}

		queue<pair<int,int>>Q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1 && vist[i][j] == 0) {
					vist[i][j] = 1;
					cnt++;
					Q.push({ i, j });
					while (!Q.empty()) {
						pair<int, int> cur = Q.front(); Q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];

							if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
							if (board[nx][ny] != 1 || vist[nx][ny] != 0) continue;
							vist[nx][ny] = 1;
							Q.push({ nx,ny });
						}
					}

				}
			}
		}
		cout << cnt << '\n';
		//다시 초기화 시키기
		for (int i = 0; i < n; i++) {
			fill(board[i], board[i] + 52, 0);
			fill(vist[i], vist[i] + 52, 0);
		}
	}
}