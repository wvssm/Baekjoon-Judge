// Authored by : wvssm
// https://www.acmicpc.net/problem/2309
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[9], sum=0, remain=0;
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		sum += a[i];
	}

	sort(a, a + 9); // �������� ����

	remain = sum - 100; // 100�� ���̰� �Է�
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = i + 1; j < 9; j++) {
			if (a[i] + a[j] == remain) break; // ���̰��� ���� ���� �� ���� ã��
		}
		if (a[i] + a[j] == remain) break;
	}

	for (int k = 0; k < 9; k++) {
		if (k == i || k == j) continue; // �� ���� �����ϰ� ���� ���
		cout << a[k] << "\n";
	}
}

// �� ������ ���� (��ü��-100) �� ���� �� ���Ҹ� ã�� ������ 7���� ���
// �ð����⵵ O(N^2)
