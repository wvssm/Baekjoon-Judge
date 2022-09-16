#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[1002];
int dist[1002][1002];
int fire[1002][1002];
int n, m;
int unfire=1;
int jx, jy;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// ��� �Է¹ޱ�
	cin >> n >> m;

	// ������ �Է¹ޱ�
	queue<pair<int, int>>Q;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '.') {
				dist[i][j] = -1;
				fire[i][j] = -1;
			}
			else if (board[i][j] == 'F') {
				Q.push({ i,j });
				unfire = 0;
			}
			else if (board[i][j] == 'J') {
				jx = i; jy = j;
			}
		}
	}

	while (!Q.empty()) {
		pair<int, int>cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (fire[nx][ny] >=0 || board[nx][ny]=='#') continue;
			fire[nx][ny] = fire[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}

	Q.push({ jx,jy });
	while (!Q.empty()) {
		pair<int, int>cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) { // ������ ��� ����
				//Ż�⿡ �����ߴٴ� �ǹ�. ť�� �Ÿ������� ���Ƿ� ������ Ż��ð� ���
				cout << dist[cur.X][cur.Y] + 1;
				return 0;
			}
			if (dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			if (unfire==0 && fire[nx][ny] <= dist[cur.X][cur.Y] + 1) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";
}

/*
���� ����Ʈ:
�Ұ� ��� ���� bfs�� ������ ��
���� ���� ���� ����
n,m ��Ĺ��� �ۿ� ����ٴ� ���� Ż���ߴٴ� ��, �̷��� �����ϸ� ����
�����:
�޸��ʰ� ���� 1002���ε� �迭�� 10002�� ������
*/
