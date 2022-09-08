#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int a[2000001] = {};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, t, x, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		a[t]++;
	}

	cin >> x;
	for (int i = 1; i < (x + 1) / 2; i++) {
		if (a[i]==1 && a[x - i] == 1) ans++;
	}
	cout << ans;
}

// 시간복잡도 : O(N+x)에 동작,
// x가 최대 200만이므로 통과에는 문제 없으나 O(N)에 비해서는 느림