// ���� 15649�� ��Ʈ��ŷ ����
#include <bits/stdc++.h>
using namespace std;

int m, n;
int arr[10];
int isused[10];

void func(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// cur��° ���� ����
	for (int i = 1; i <= n; i++) {
		if (!isused[i]) {
			arr[cur] = i; 
			isused[i] = 1;
			func(cur + 1);
			isused[i] = 0; // ��� ��� ���� ���� ���ƿ�
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);
}