// Authored by : wvssm
// https://www.acmicpc.net/problem/10828
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	stack<int> stk;
	int n, val;
	string opt;
	cin >> n;
	while (n--) {
		cin >> opt;
		if (opt == "push") {
			cin >> val;
			stk.push(val);
		}
		else if (opt == "pop") {
			if (!stk.empty()) {
				cout << stk.top() <<'\n';
				stk.pop();
			}
			else cout << -1 << '\n';
		}
		else if (opt == "size") cout << stk.size() << '\n';
		else if (opt == "empty") cout << stk.empty() << '\n';
		else if (opt == "top") {
			if (!stk.empty()) cout << stk.top() << '\n';
			else cout << -1 << '\n';
		}
	}
}