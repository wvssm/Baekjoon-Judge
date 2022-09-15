// Authored by : wvssm
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<char> stk;
	string str;
	int p = 0, total = 0;

	cin >> str;
	for (auto c : str) {
		if (c == '(') {
			stk.push(c);
			p = 0;
		}
		else if (c == ')') {
			// 레이저일 때
			if (p == 0) {
				if (!stk.empty()) {
					stk.pop();
					p = 1;
				}
				total += (int)stk.size();
			}
			// 레어저가 아닐 떼
			else {
				if (!stk.empty()) {
					stk.pop();
					total += 1;
					p = 1;
				}
			}
		}
	}
	cout << total;
}