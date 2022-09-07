#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int min = 101, sum = 0, input;
	
	for (int i = 0; i < 7; i++) {
		cin >> input;
		
		if (input % 2 == 1) { // if (input & 1)도 가능, (&연산 전부 0됨)
			if (min > input) min = input;
			sum += input;
		}
	}

	if (sum == 0) cout << -1;
	else cout << sum << "\n" << min;
}