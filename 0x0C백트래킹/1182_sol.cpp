// ���� 1182 - �κм����� ��, �ַ��
#include <bits/stdc++.h>
using namespace std;

int n, s;
int cnt = 0; // ���� �ʱ�ȭ���ֱ�
int arr[30];

void func(int cur, int tot) {
	if (cur == n) {
		if (tot == s) {
			cnt++;
		}
		return; // Ż�ⱸ�� ��ġ �߿�
	}

	// ���� �������� ��� ǥ���ؾ� ���� ���� ��������
	func(cur + 1, tot); // �κ����տ� ���Ҹ� �������� �ʴ� ���
	func(cur + 1, tot + arr[cur]); // �κ����տ� ���Ҹ� �����ϴ� ���
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	func(0, 0);
	if (s == 0) cnt--; // �������� ��� ����
	cout << cnt;
}