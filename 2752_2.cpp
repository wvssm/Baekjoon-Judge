#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	for (auto i : a) {
		cout << i << ' ';
	}
}

// sort() 함수 사용
// 시간복잡도: O(NlgN)