// ���� 1182
// ��Ʈ��ŷ�� �������� ������, �Ʒ��� �� �������� ���¸� ����

#include <bits/stdc++.h>
using namespace std;
int n, s, cnt=0;
int arr[22];

void func(int cur, int sum) {
	// �̿��� ����Ʈ�� ������ ���� ��
	if (cur == n) {
		if (s == sum) {
			cnt++;
		}
		return;
	}

	// �̿����� �� ������ Ǫ�� ��
	func(cur + 1, sum); // ���Ҹ� ���þ��� ���
	func(cur + 1, sum + arr[cur]); // ���Ҹ� ������ ���
} 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	func(0,0);
	if (s == 0) cout << cnt - 1; // ũ�Ⱑ ����ϱ� ������ ���� (�̰Ŷ��� ���䳪��)
	else cout << cnt;
}