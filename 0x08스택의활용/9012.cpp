#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, err;
	string str;
	
	cin >> t;
	
	while (t--) {
		stack<char>s;
		err = 0;
		cin >> str;
		for (auto c : str) {
			if (c == '(') s.push(c);
			else if(c == ')') {
				if (!s.empty()) s.pop();
				else {
					err = 1;
					break;
				}
			}
		}
		if (!s.empty() || err == 1) cout << "NO";
		else cout << "YES";
		cout << '\n';
	}
}