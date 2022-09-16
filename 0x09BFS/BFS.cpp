#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502] = { {0,0,0,0} }; //보드판
bool vis[502][502]; //방문
int n, m; //행렬
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; //4방향

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>>Q; //큐생성
	vis[0][0] = 1; //시작점 방문표시
	Q.push({ 0,0 });

	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop(); //front꺼낸다음 pop
		cout << '(' << cur.X << ", " << cur.Y << ") -> "; //보기쉽게 출력
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //범위에 벗어난 경우
			if (vis[nx][ny] || board[nx][ny] != 1) continue; //이미 갔거나 갈 수 없는 길
			vis[nx][ny] = 1;
			Q.push({ nx,ny });
		}
	}
}