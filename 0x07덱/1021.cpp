// Authored by : wvssm
#include <bits/stdc++.h>
using namespace std;

int main() {
	queue<int> q;
	int n, m, ans=0, cnt=0;
	int a[51];

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		while (a[i] != q.front()) {
			q.push(q.front());
			q.pop();
			cnt++;
		}
		ans += min((int)q.size() - cnt, cnt);
		q.pop();
		cnt = 0;
	}
	cout << ans;
}