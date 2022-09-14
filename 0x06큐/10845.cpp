#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> q;
	int n, input;
	string opt;
	cin >> n;
	while (n--) {
		cin >> opt;
		if (opt == "push") {
			cin >> input;
			q.push(input);
		}
		else if (opt == "front") {
			if (!q.empty()) cout << q.front() << '\n';
			else cout << -1 << '\n';
		}
		else if (opt == "back") {
			if (!q.empty()) cout << q.back() << '\n';
			else cout << -1 << '\n';
		}
		else if (opt == "pop") {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop();
			}
			else cout << -1 << '\n';
		}
		else if (opt == "size") cout << q.size() << '\n';
		else if (opt == "empty") cout << q.empty() << '\n';
	}
}