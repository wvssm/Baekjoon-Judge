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

// �ð����⵵: 0(N)
// �ɸ� �ð�: 965ms
// �޸�: �� 12byte ���