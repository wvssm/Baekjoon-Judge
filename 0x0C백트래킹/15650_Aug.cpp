#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int isused[10]; // ������ ���� ���� ���Ǿ�����
int isused_2[50000]; // �� ���� ������ ���Ǿ����� Ȯ��
// ��� ������ ���� ������� ���� (2,3,4)�� (1,4,6)�� ������ �ȵ�, �׷��� ������ �հ� �� �Ѵ� Ȯ���ϱ�� ��, ������ ��+������ ��*100�� �ִ��� isused�� ���� Ȯ��

void func(int cur,int mul, int plus) {
	// ��� �ܰ谡 �ϼ��Ǿ��� ��, ������ �̷� ���� ������ �������� Ȯ�� (���� �� + ���� ��*100 ������ Ȯ��)
	if (cur == M) {
		if (!isused_2[mul+plus*100]) {
			for (int i = 0; i < M; i++) {
				cout << arr[i] << ' ';
			}
			cout << '\n';
			isused_2[mul+plus*100] = 1;
			return;
		}
	}

	// �ܰ躰�� ���� �̱�
	for (int i = 0; i < N; i++) {
		if (!isused[i]) {
			isused[i] = 1;
			arr[cur] = i + 1;
			func(cur + 1, mul * arr[cur],plus+arr[cur]);
			isused[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	func(0, 1, 0);
}