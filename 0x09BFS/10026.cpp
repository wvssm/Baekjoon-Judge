#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[101];
bool vis[101][101];
int n;
int nRG, RG;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>>Q;

void BFS(int i, int j, string opt) {
	vis[i][j] = 1;
	Q.push({ i,j });
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (vis[nx][ny] != 0 || opt.find(board[nx][ny]) == std::string::npos) {
				continue;
			}
			vis[nx][ny] = 1;
			Q.push({ nx,ny });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	int b=0, r=0, g=0, rg=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'B' && vis[i][j]==0) {
				BFS(i, j, "B");
				b++;
			}
			else if (board[i][j] == 'R' && vis[i][j] == 0) {
				BFS(i, j, "R");
				r++;
			}
			else if (board[i][j] == 'G' && vis[i][j] == 0) {
				BFS(i, j, "G");
				g++;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		fill(vis[i], vis[i] + 101, 0);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((board[i][j] == 'R' || board[i][j]=='G')&& vis[i][j] == 0) {
				BFS(i, j, "RG");
				rg++;
			}
		}
	}
	cout << r + g + b << ' ' << rg+b;
}

/*
���� �ذ�: 
�Ϲ� = R,G,B ���� BFS ���ؼ� ���� ���� ��
RG ȯ�� = RG BFS ���ؼ� RG + B ��

�����:
�湮������ vis=1�ؾߵǴµ� vis=0��
ó���� ���� �� &&vis[0]==0 �̶�� �湮�������� �� �� �ִٴ� ���� �ȳ���
*/