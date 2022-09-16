#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502] = { {0,0,0,0} }; //������
bool vis[502][502]; //�湮
int n, m; //���
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; //4����

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>>Q; //ť����
	vis[0][0] = 1; //������ �湮ǥ��
	Q.push({ 0,0 });

	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop(); //front�������� pop
		cout << '(' << cur.X << ", " << cur.Y << ") -> "; //���⽱�� ���
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //������ ��� ���
			if (vis[nx][ny] || board[nx][ny] != 1) continue; //�̹� ���ų� �� �� ���� ��
			vis[nx][ny] = 1;
			Q.push({ nx,ny });
		}
	}
}