// 연속된 정수 받기가 더 까다로웠다.
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m;
int board[105][105];
int vis[105][105];
int min_num;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void BFS(int x, int y) {
	queue<pair<int, int>> q;
	q.push({x,y});

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] != 1) continue;

			vis[nx][ny] = vis[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
		}


	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			board[i][j] = s[j] - '0';
		}
	}
	vis[0][0] = 1;
	BFS(0, 0);
	cout << vis[n-1][m-1];
}