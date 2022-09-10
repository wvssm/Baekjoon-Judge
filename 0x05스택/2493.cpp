// Authored by : wvssm
// 시간초과로 실패
// https://www.acmicpc.net/problem/2493
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	stack<int> s, t;
	vector<int> ans;
	int n, tower, cnt = 0, val;

	cin >> n;
	while (n--) {
		cin >> tower;
		if (s.empty()) {
			ans.push_back(0);
			s.push(tower);
			continue;
		}

		t = s;
		while (t.size()) {
			if (t.top() >= tower) {
				ans.push_back(t.size());
				break;
			}
			t.pop();
		}
		if (t.size() == 0) ans.push_back(0);
		s.push(tower);
	}

	for (auto i : ans) cout << i << ' ';
}