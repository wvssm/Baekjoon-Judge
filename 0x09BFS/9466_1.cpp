// ��ŷ���� �����ڵ�, O(N^2)�̶� �ð��ʰ�
#include <bits/stdc++.h>
using namespace std;
int board[100002];
int vis[100002];
int n;

int isCycle(int x) {
	int now = x;
	for (int i = 0; i < n; i++) {
		int nxt = board[now];
		now = nxt;
		// now = board[now] �̷��� �ᵵ ��
		if (now == x) return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> board[i];
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!isCycle(i)) {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
}

/*
����Ŭ�� ���Ե��� ���� ������ ������ ����ϴ� ����
O(N^2)Ǯ��: ������ ���ҿ��� N�� ��ŭ �̵�
ĭ �̵��ϴ� ���� �ڽŰ� �Ȱ��� ���Ҹ� ������ ������ cycle�� �ƴ� ����
����Ŭ�� ���ԵǾ� ������ Nĭ �̵��ϴ� ���� �ڱ� �ڽ��� �ݵ�� ������ ��

�ð��ʰ� ���� Ǯ��
*/