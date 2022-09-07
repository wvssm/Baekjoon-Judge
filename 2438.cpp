// https://www.acmicpc.net/problem/2438
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		k = i;
		while (k--) cout << "*";
		cout << "\n";
	}
}