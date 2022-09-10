// Authored by : wvssm
// https://www.acmicpc.net/problem/1874
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int>s;
	int n, val, pre=0, num=1;
	string ans = "";
	cin >> n;
	
	while (n--) {
		cin >> val;
		if (val > pre) {
			while (num != val+1) {
				s.push(num);
				num++;
				ans+="+\n";
			}
			s.pop();
			ans += "-\n";
		}
		else {
			//cout << "top:" << s.top();
			if (val == s.top()) {
				s.pop();
				ans += "-\n";
			}
			else {
				cout << "NO";
				return 0;
			}
		}
		pre = val;
	}
	cout << ans;
}