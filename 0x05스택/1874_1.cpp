// Authored by : haneulkimdev
// Co-authored by : BaaaaaaaaaaarkingDog
// https://www.acmicpc.net/problem/1874
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int>s;
	int n, t, cnt = 1;
	string ans = "";
	cin >> n;

	while (n--) {
		cin >> t;
		while (cnt<=t) {
			s.push(cnt++);
			ans += "+\n";
		}
		if (s.top() != t) {
			cout << "NO";
			return 0;
		}

		s.pop();
		ans += "-\n";
	}
	cout << ans;
}

/* 각 원소들 모두 pop해야되기 때문에
조건을 나눌 필요없고 맨 마지막에 배치하면 됨*/ 