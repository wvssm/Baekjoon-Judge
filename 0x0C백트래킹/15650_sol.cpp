#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int isused[10];

void func(int cur) {
	if (cur == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// ���������� ���� �̴¹�, ������ ������ �ʴ� ���ڵ��� ���ʴ�� �̴´�.
	// ���� ���� ���� ���� �� ���� ������ ū ������ ���� ������ for���� ���� �ڸ� ������
	// ū ������ ��ȯ���Ѿ� �Ѵ�.
	int st = 1;
	if (cur != 0) st = arr[cur - 1] + 1; //���� �ڸ� ������ 1 ���� ������ ��ȯ�ؾ���
	
	for (int i = st; i <= N; i++) {
		if (isused[i]) {
			arr[cur] = i;
			isused[i] = 1;
			func(cur + 1);
			isused[i] = 0;
		}
	}
}