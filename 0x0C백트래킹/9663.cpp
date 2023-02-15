//// ���� 9663 - N-Queen
#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
int isused_1[30], isused_2[30], isused_3[30]; // �� �迭�� ���� �������� �ٷ� Ȯ���ϴ� ���� �ٽ�

void solve(int cur) {
	if (cur == n) { // n���� �� ��δ� ���� ��ġ ��������
		cnt++; // �� ����
		return; // ����
	}

	for (int i = 0; i < n; i++) {
		if (isused_1[i]) continue; // �� �˻�
		else if (isused_2[cur + i]) continue; // ���� �밢�� �˻�
		else if (isused_3[cur - i + n - 1]) continue; // ���� �밢�� �˻�
		isused_1[i] = 1;
		isused_2[cur + i] = 1;
		isused_3[cur - i + n - 1] = 1;
		solve(cur + 1); // ���� �࿡ ���� ���� ���� ��ġ ���ϱ�
		isused_1[i] = 0;
		isused_2[cur + i] = 0;
		isused_3[cur - i + n - 1] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	solve(0);
	cout << cnt;
}