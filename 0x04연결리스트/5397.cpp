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
				L.insert(cursor, c); // (��ó��) ����´� ���̳�� �ۿ� ����, �� �Ŀ� ���� �߰��ص� Ŀ���� ���� ���
				// ���ο� ���Ҵ� �ش� ���ͷ�����(��ġ)�տ� ��ӵǰ�, ����Ű�� ���ͷ����ʹ� ��� �ǵ��̴�
			}
		}
		for (auto c : L) cout << c;
		cout << '\n';
	}
}