#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int num = 0; // 그림의 개수
	int mx = 0; // 그림 크기 최댓값

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { //충격 오타때문에 틀림, m을 n이라 씀
			if (vis[i][j] || board[i][j] == 0) continue;
			num++; // 그림의 수 증가 (새로운 곳에서 출발 할 때)
			queue<pair<int, int>>Q;
			vis[i][j] = 1;
			Q.push({ i,j });
			int area = 0; // 그림의 너비
			while (!Q.empty()) {
				area++; //큐에서 하나 뺄 때 마다 -> 너비 증가
				pair<int, int> cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] == 1 || board[nx][ny] != 1) continue;

					vis[nx][ny] = 1;
					Q.push({ nx,ny });
				}
			}
			mx = max(mx, area);
		}
	}
	cout << num << '\n' << mx;
}

/*
디버깅 :
오타때문에 틀림, for문에서 i<n, j<m 이렇게 적어야 되는데 둘다 n 써버림
*/ 