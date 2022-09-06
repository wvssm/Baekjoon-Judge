#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x, val;
	cin >> n >> x;

	while (n--) {
		cin >> val;
		if (val < x) cout << val << " ";
	}
	return 0;
}

// 시간복잡도: 0(N)
// 걸린 시간: 965ms
// 메모리: 약 12byte 사용