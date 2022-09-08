//https://www.acmicpc.net/problem/10808
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string alpha = "abcdefghijklmnopqrstuvwxyz";
int arr[26];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string input;
	cin >> input;
	for (auto& k : input) {
		for (int i = 0; i < alpha.size(); i++) {
			if (alpha[i] == k) arr[i]++;
		}
	}

	for (auto& i : arr) cout << i << ' ';
}
// 시간 복잡도 : O(26N)