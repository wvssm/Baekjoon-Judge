#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> dq;
	int n, x;
	string opt;
	
	cin >> n;

	while (n--) {
		cin >> opt;
		if (opt == "push_front") {
			cin >> x;
			dq.push_front(x);
		}
		else if (opt == "push_back") {
			cin >> x;
			dq.push_back(x);
		}
		else if (opt == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			else cout << -1 << '\n';
		}
		else if (opt == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else cout << -1 << '\n';
		}
		else if (opt == "size") {
			cout <<dq.size() << '\n';
		}
		else if (opt == "empty") {
			cout << dq.empty() << '\n';
		}
		else if (opt == "front") {
			if (!dq.empty()) {
				cout << dq.front() << '\n';
			}
			else cout << -1 << '\n';
		}
		else if (opt == "back") {
			if (!dq.empty()) {
				cout << dq.back() << '\n';
			}
			else cout << -1 << '\n';
		}
	}
}