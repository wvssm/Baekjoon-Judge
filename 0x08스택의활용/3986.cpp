// Authored by : wvssm
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n ,ans=0;
	string str;
	cin >> n;
	while (n--) {
		stack<char> s;
		cin >> str;
		for (auto c : str) {
			if (s.empty()) s.push(c);
			else if (c != s.top()) s.push(c);
			else if (c == s.top()) s.pop();
		}
		if (s.empty()) ans++;
	}
	cout << ans;
}