// https://www.acmicpc.net/problem/13300
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int a[13];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, s, y, ans=0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s >> y;
		a[2 * y - s]++;
	}

	for (int i = 0; i < 13; i++) {
		ans += (int)ceil(a[i] / (double)k);
		/*ans += a[i] / k;
		if (ans % k) ans++;*/
	}
	cout << ans;
}