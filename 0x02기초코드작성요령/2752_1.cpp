#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	int d, e, f;

	d = min({ a, b, c });
	e = max({ a, b, c });
	f = a + b + c - d - e;

	cout << d << ' ' << f << ' ' << e << ' ';
}

// min, max 함수 사용
// 시간복잡도: 0(N)