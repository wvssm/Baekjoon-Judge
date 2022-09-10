// Authored by : wvssn
// https://www.acmicpc.net/problem/5397
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int l;
	string psword;
	list<char>L = {};

	cin >> l;
	while (l--) {
		list<char>L = {};
		auto cursor = L.begin();
		int appear = 0;
		cin >> psword;
		for (auto c : psword) {
			if (c == '<') {
				if (cursor != L.begin()) cursor--;
			}
			else if (c == '>') {
				if (cursor != L.end()) cursor++;
			}
			else if (c == '-') {
				if (cursor != L.begin()) cursor = L.erase(--cursor);
			}
			else {
				L.insert(cursor, c); // (맨처음) 빈상태는 더미노드 밖에 없음, 그 후에 원소 추가해도 커서는 더미 노드
				// 새로운 원소는 해당 이터레이터(위치)앞에 계속되고, 가리키는 이터레이터는 계속 맨뒤이다
			}
		}
		for (auto c : L) cout << c;
		cout << '\n';
	}
}