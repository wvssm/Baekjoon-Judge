// https://www.acmicpc.net/problem/2577
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int occur[10];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int input, mul = 1;

	for (int i = 0; i < 3; i++) {
		cin >> input;
		mul *= input;
	}

	string mul_str = to_string(mul);
	for (auto& i:mul_str) occur[i-'0'] += 1;

	for (auto& j : occur) cout << j << "\n";
}
// 문자열로 바꾼 뒤에 수를 세는 풀이