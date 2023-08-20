// ���� 15654 N�� M (5)
// ���Ҹ� ���� ����� �迭�� ���� ���� �ƴ϶�
// ����� �ε��� ��ȣ�� �迭�� �����س���
// �ε����� ���� �Է� �迭�� ���� ����
#include <bits/stdc++.h>
using namespace std;

int n, m;
int input[10];
int arr[10];
int isused[10];

void func(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++) {
			cout << input[arr[i]] << ' '; // �迭 ��ü�� �ε����� ��� ����
			// �ε����� ��ġ�ؼ� �� ���� ���� �����
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!isused[i]) { // 1,2,3,4�� ����� �ε��� ���� ��ġ�ϱ�
			arr[cur] = i;
			isused[i] = 1;
			func(cur + 1);
			isused[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> input[i];
	sort(input, input + n);
	func(0);
}