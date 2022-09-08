#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, x, ans;
int input[100001], arr[2000001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i]; // ���� ����
		arr[input[i]] += 1; // ���� ���� ���� ����
	}
	cin >> x;

	for (int i = 0; i < n; i++) {
		if (x <= input[i]) continue;
		if (arr[x - input[i]] == 1) ans++; // �ش� ������ ���ҿ� ���� x �Ǵ� ���Ұ� �����ϴ��� Ȯ��
	}
	cout << ans / 2;

	/*
	���ǿ� �ش��ϴ� ���� �����ϴ���(occur) Ȯ���ϰ�, �� ������ occur ǥ��
	for (int i = 0; i < n; i++) {
		if (x - input[i] > 0 && arr[x - input[i]]) ans++;
		arr[input[i]] = 1;
	}
	cout << ans;
	�̷��� �ۼ��ϸ� ���ڽ��� ���ݸ� ����
	*/
}
// �������⵵: O(2000000), �ð����⵵ O(N)