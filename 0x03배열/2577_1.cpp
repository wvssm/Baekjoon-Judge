#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	int total = a * b * c;

	int d[10] = {};
	while (total > 0) {
		d[total % 10] += 1;
		total /= 10;
	}

	for (int i : d) cout << i << "\n";
}

// �������� �������� �̿��� Ǯ��