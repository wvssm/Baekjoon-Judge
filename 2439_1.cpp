#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int j = 0;
		for (; n - i - 1; j++) cout << ' ';
		for (; j < n; j++) cout << "*";
		cout << "\n";
	}
}

// �����̶� *�̾����ٰ� �����ϰ� for�� �ۼ�