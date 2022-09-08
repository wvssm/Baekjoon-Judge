#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	if (a < b) {
		if (a < c) {
			cout << a << " ";

			if (b < c) cout << b << " " << c;
			else       cout << c << " " << b;
		}
		else cout << c << " " << a << " " << b;
	}

	else {
		if (a < c) cout << b << " " << a << " " << c;
		else {
			if (b < c) cout << b << " " << c << " " << a;
			else       cout << c << " " << b << " " << a;
		}
	}
}

// if문 노가다 코드
// 시간 복잡도: O(N)