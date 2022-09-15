// Authored by : wvssm
#include <bits/stdc++.h>
using namespace std;

int main() {
	stack<char>s;
	stack<pair<int,int>>val;
	string str;
	int ans = 0;

	cin >> str;
	for (auto c : str) {
		if (c == '(') s.push('(');
		else if (c == '[') s.push('[');
		else if (c == ')') {
			if (!s.empty() && s.top() == '(') {
				if (!val.empty()) {
					int tmp=0;
					while (!val.empty() && val.top().second == (int)s.size()) {
						tmp += val.top().first;
						val.pop();
					}
					if (tmp == 0) tmp = 1;
					tmp = tmp * 2;
					s.pop();
					val.push({ tmp, (int)s.size() });
				}
				else {
					s.pop();
					val.push({ 2, (int)s.size() });
				}
			}
			else {
				cout << 0;
				return 0;
			}
		}
		else if (c == ']') {
			if (!s.empty() && s.top() == '[') {
				if (!val.empty()) {
					int tmp = 0;
					while (!val.empty()&& val.top().second == (int)s.size()) {
						tmp += val.top().first;
						val.pop();
					}
					if (tmp == 0) tmp = 1;
					tmp = tmp * 3;
					s.pop();
					val.push({ tmp, (int)s.size() });
				}
				else {
					s.pop();
					val.push({ 3, (int)s.size() });
				}
			}
			else {
				cout << 0;
				return 0;
			}
		}
	}

	if (s.empty()) {
		while (!val.empty() && val.top().second == 0) {
			ans += val.top().first;
			val.pop(); // pop을 안해줬어서 오류
		}
		cout << ans;
	}
	else cout << 0;
}