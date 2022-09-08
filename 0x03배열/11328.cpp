// Authored by : wvssm
// https://www.acmicpc.net/problem/11328
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s1, s2;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int alpha[26] = {};
		int alpha2[26] = {};
		cin >> s1 >> s2;
		for (auto& c : s1) alpha[c - 'a']++;
		for (auto& d : s2) alpha2[d - 'a']++;

		equal(alpha, alpha + 26, alpha2, alpha2 + 26) ?
			cout << "Possible\n" :
			cout << "Impossible\n";
	}
}

// �� ���ڿ��� ���ĺ��� �����ϴ� �迭�� 2�� ���� �ΰ��� ������ ��
// �ð����⵵ : O(3*N)