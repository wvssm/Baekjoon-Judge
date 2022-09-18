//내가짠것, 시간초과 실패
#include <bits/stdc++.h>
using namespace std;
int board[100002];
int vis[100002];

int bfs(int x) {
	int end = 0;
	vis[x] = 1;
	queue<int>Q;
	Q.push(x);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		int nxt = board[cur]; 
		if (vis[nxt] != 0) {
			end = nxt;
			continue;
		}
		//cout << "push: " << nxt << '\n';
		vis[nxt] = 1;
		Q.push(nxt);
	}
	return end;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, cnt;
	cin >> t;
	while (t--) {
		cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> board[i];
		}

		for (int i = 1; i <= n; i++) {
			if (vis[i] != 0) continue;
			int res = bfs(i);
			//cout << "res: " << res << '\n';
			if (res != i) {
				fill(vis, vis + n+1, 0);
				cnt++;
			}
		}
		cout << cnt << '\n';
		fill(vis, vis + n+1, 0);
	}
}