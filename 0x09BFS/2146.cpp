#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[102][102];
int vis[102][102];
int dist[102][102];
int island_name[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n;
queue<tuple<int, int, int>> b_Q; 


// 입력 함수 O(N^2)
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
}

// 육지를 구분하는 함수 O(N^2)
void count_island() {
	queue<pair<int, int>> Q;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0 || vis[i][j] != 0) continue;
			cnt++;
			vis[i][j] = cnt;
			Q.push({ i,j });

			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

					// 육지 가장자리에 있는 바다를 큐안에 집어 넣기
					if (board[nx][ny] == 0 && vis[nx][ny] == 0) {
						vis[nx][ny] = -cnt;
						island_name[nx][ny] = cnt;
						dist[nx][ny] = 1;
						b_Q.push({ nx,ny,cnt });
					}
					if (board[nx][ny] == 0 || vis[nx][ny] != 0) continue;

					vis[nx][ny] = cnt;
					Q.push({ nx,ny });
				}
			}
		}
	}
}

// 다리를 만드는 함수 O(N^2)
int make_bridge() {
	int opt = 0;
	int stop_dist = 0;
	vector<int>ans;

	while (!b_Q.empty()) {
		int x, y, num = 0;
		tie(x, y, num) = b_Q.front(); b_Q.pop();
		if (opt == 1 && dist[x][y] > stop_dist) break; // 이전 단계에서 다리가 만들어졌으면 종료
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 범위를 벗어났을 때
			if (num != vis[nx][ny] && vis[nx][ny] > 0) { // 또 다른 육지에 도달했을 때
				return dist[x][y];
			}
			if (num != island_name[nx][ny] && dist[nx][ny] > 0) {  // 다른 육지에서 측정하기 시작한 거리와 만났을 때
				//cout << "here: " << nx << ", " << ny << ' '<< dist[nx][ny] + dist[x][y]<< '\n';
				stop_dist = dist[x][y];
				opt = 1;
				ans.push_back(dist[nx][ny] + dist[x][y]);
				continue;
			}
			if (board[nx][ny] != 0 || dist[nx][ny] > 0) continue; // 바다가 아니고 이미 방문했던 곳일 때
			dist[nx][ny] = dist[x][y] + 1;
			island_name[nx][ny] = num;
			b_Q.push({ nx,ny,num });
		}
	}
	return *min_element(ans.begin(),ans.end()); // 만들어진 다리 중 최솟값 반환
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	count_island();
	int ans = make_bridge();
	cout << ans;
}

// 시간복잡도: O(3N^2)
// 공간복잡도: O(4N^2)