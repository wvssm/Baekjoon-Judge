#include <bits/stdc++.h>
using namespace std;
#define MX 100002
int dist[MX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(dist, dist + MX , -1); // MX+1������ ���� ��Ƽ� out of bound �ɸ�

	int n, k;
	cin >> n >> k;
	if (n == k) {
		cout << 0;
		return 0;
	}
	deque<int>DQ;
	dist[n] = 0;
	DQ.push_back(n);
	while (!DQ.empty()) {
		int cur = DQ.front(); DQ.pop_front();
		for (int nxt : {cur - 1, cur + 1, cur * 2}) {
			if (nxt < 0 || nxt>MX-1) continue;
			if (dist[nxt] > -1) continue;

			if (nxt == cur * 2) {
				//cout << cur << ' ' << nxt << '\n';
				dist[nxt] = dist[cur];
				DQ.push_front(nxt);
			}
			else {
				dist[nxt] = dist[cur] + 1;
				DQ.push_back(nxt);
			}

			if (nxt == k) {
				//cout << nxt << '\n';
				cout << dist[nxt];
				return 0;
			}
		}
	}
}

//�ð����⵵: O(N)
//�������⵵: O(N+2)