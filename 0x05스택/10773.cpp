// Authored by : wvssm
// https://www.acmicpc.net/problem/10773
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<int> s;
	int n, val, ans=0;

	cin >> n;

	while (n--) {
		cin >> val;
		if (val == 0) {
			if (!s.empty()) s.pop();
		}
		else s.push(val);
	}

	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}
	cout << ans;
}