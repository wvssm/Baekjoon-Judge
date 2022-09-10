// Authored by : wvssn
// https://www.acmicpc.net/problem/1158
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	string ans = "<";
	cin >> N >> K;

	list<int>L = {};

	for (int i = 1; i <= N; i++) {
		L.push_back(i);
	}

	auto t = L.begin();
	while (L.size()) {
		for (int i = 0; i < K-1; i++) {
			if (t == --L.end()) {
				t = L.begin();
				continue;
			}
			t++;
		}
		
		ans += to_string(*t)+", ";
		t = L.erase(t);
		if (t == L.end()) t = L.begin();
	}
	ans.pop_back();
	ans.pop_back();
	ans += ">";
	cout << ans;
}
// STL list를 이용한 풀이