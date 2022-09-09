// Authored by : wvssn
// https://www.acmicpc.net/problem/1406
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	list<char>L = {};
	string s;
	int n;
	char c, input;

	cin >> s;
	for (auto c : s) L.push_back(c);

	auto cursor = L.end(); // 커서 시작점

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c == 'P') cin >> input;
		switch(c) {
		case 'L':
			if (cursor != L.begin()) cursor--;
			break;
		case 'D':
			if (cursor != L.end()) cursor++;
			break;
		case 'B':
			if(cursor!=L.begin()) cursor = L.erase(--cursor); // 한칸 앞의 것을 삭제
			break;
		case 'P':
			L.insert(cursor, input);
			break;
		}
	}
	for (auto i : L) cout << i;
}
