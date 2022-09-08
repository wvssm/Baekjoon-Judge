// Authored by : wvssm
// https://www.acmicpc.net/problem/1919
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int alpha[26];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str1, str2;
	int ans = 0;
	cin >> str1 >> str2;

	for (auto c : str1) alpha[c - 'a']++;
	for (auto c : str2) alpha[c - 'a']--;

	for (auto i : alpha) ans += abs(i);
	cout << ans;
}