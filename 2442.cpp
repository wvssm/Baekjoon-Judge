#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int j = 0;
		for (; j < n - i - 1; j++) cout << ' ';
		for (; j < n; j++) cout << '*';
		for (int k = 0; k < i; k++) cout << "*";
		cout << "\n";
	}

	//sol2) 모양으로만 생각안하고 식으로 구함
	//별 = 2n - 1

	//for (int i = 1; i <= n; i++) {
	//	for (int j = 0; j < n - i; j++) cout << ' ';
	//	for (int j = 0; j < 2 * i - 1; j++) cout << "*";
	//	cout << "\n";
	//}
}