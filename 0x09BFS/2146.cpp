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


// �Է� �Լ� O(N^2)
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
}

// ������ �����ϴ� �Լ� O(N^2)
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

					// ���� �����ڸ��� �ִ� �ٴٸ� ť�ȿ� ���� �ֱ�
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

// �ٸ��� ����� �Լ� O(N^2)
int make_bridge() {
	int opt = 0;
	int stop_dist = 0;
	vector<int>ans;

	while (!b_Q.empty()) {
		int x, y, num = 0;
		tie(x, y, num) = b_Q.front(); b_Q.pop();
		if (opt == 1 && dist[x][y] > stop_dist) break; // ���� �ܰ迡�� �ٸ��� ����������� ����
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // ������ ����� ��
			if (num != vis[nx][ny] && vis[nx][ny] > 0) { // �� �ٸ� ������ �������� ��
				return dist[x][y];
			}
			if (num != island_name[nx][ny] && dist[nx][ny] > 0) {  // �ٸ� �������� �����ϱ� ������ �Ÿ��� ������ ��
				//cout << "here: " << nx << ", " << ny << ' '<< dist[nx][ny] + dist[x][y]<< '\n';
				stop_dist = dist[x][y];
				opt = 1;
				ans.push_back(dist[nx][ny] + dist[x][y]);
				continue;
			}
			if (board[nx][ny] != 0 || dist[nx][ny] > 0) continue; // �ٴٰ� �ƴϰ� �̹� �湮�ߴ� ���� ��
			dist[nx][ny] = dist[x][y] + 1;
			island_name[nx][ny] = num;
			b_Q.push({ nx,ny,num });
		}
	}
	return *min_element(ans.begin(),ans.end()); // ������� �ٸ� �� �ּڰ� ��ȯ
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	count_island();
	int ans = make_bridge();
	cout << ans;
}

// �ð����⵵: O(3N^2)
// �������⵵: O(4N^2)