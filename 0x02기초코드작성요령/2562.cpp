// https://www.acmicpc.net/problem/2562
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int input, max=0, index=0;
	
	for (int i = 0; i < 9; i++) {
		cin >> input;
		if (input > max) {
			max = input;
			index = i + 1;
		}
	}

	cout << max << "\n" << index;
}

// 시간복잡도 : O(n)