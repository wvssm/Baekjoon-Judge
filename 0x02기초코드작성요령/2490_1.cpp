#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int result, input;
	string res = "DCBAE";

	for (int r = 0; r < 3; r++) {
		result = 0;
		for (int c = 0; c < 4; c++) {
			cin >> input;
			result += input;
		}
		cout << res[result] << '\n';
	}
}

// �ð����⵵ : O(N^2)
// ���� 3���� ��������, �޸� ����
// �迭 �ʿ���� input���� ��� �޾ƹ�����, 4���� ���� ������ ���±���
// ���� ���� index�� ����Ͽ� string�� �迭�� ���� �������°� ���