#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<char> ans;
	ans.reserve(3);
	int a[3][4];
	int cnt;
	for (int i = 0; i < 3; i++) {
		cnt = 0;
		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
		for (int j = 0; j < 4; j++) {
			if (a[i][j] == 0) cnt++;
		}
		switch (cnt) {
		case 0:
			ans.push_back('E');
			break;
		case 1:
			ans.push_back('A');
			break;
		case 2:
			ans.push_back('B');
			break;
		case 3:
			ans.push_back('C');
			break;
		case 4:
			ans.push_back('D');
			break;
		}
	}
	
	for (auto i : ans) {
		cout << i << "\n";
	}
}

// �ð����⵵ : O(N^2)
// �ɸ� �ð� : 965ms
// ��¥ ���������� �ٷ� ¥����, 3�� �Է� �Ѳ����� �ް� 3�� �Ѳ����� ��� ���