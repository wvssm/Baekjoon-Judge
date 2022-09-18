// ���� ������ ���������� ����� �ȳ���, ����
#include <bits/stdc++.h>
using namespace std;
int board[100002];
int vis[100002];
int cir[100002];
int n;

int isCycle(int x) {
	int now = x;
	if (cir[now] == 2) return 0;
	if (cir[now] == 1) return 1;
	for (int i = 0; i < n; i++) {
		// ù��° ���
		if (cir[now] > 0) {
			int a=x;
			while(a!=now) {
				a = x;
				cir[a] = 1;
				a = board[a];
			}
			return 1;
		}
		int nxt = board[now];
		now = nxt;

		// 3��° ���
		if (now == x) {
			int d = 0;
			cir[now] = 2;
			while (d!=now) {
				d = board[d];
				cir[d] = 2;
			}
			return 0;
		}
	}
	// 2��° ���
	int cur = now;
	cir[now] = 2;
	while (1) {
		cur = board[cur];
		cir[cur] = 2;
		if (cur == now) break;
	}
	int cur2 = x;
	cir[x] = 1;
	while (1) {
		cur2 = cir[cur2];
		cir[cur2] = 1;
	}
	return 1;
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

		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += isCycle(i);
		}
		cout << sum << '\n';
	}
}

/*
����Ŭ�� ���Ե��� ���� ������ ������ ����ϴ� ����

O(N)Ǯ��: ������ ���� x���� N�� ��ŭ ĭ �̵�

1. ����Ŭ�� ���Ե� �л� or ����Ŭ�� ���Ե��� ���� �л� ��湮
x�� ����Ŭ�� ����x, �������� �湮�� �л��� �ϴ� ����Ŭ ���� x

2. x�� �ƴ� �ٸ� �湮�� �л� y ��湮
x�� ����Ŭ ����x, y�� ����Ŭ ����
y���� ����� �ٽ� y���� ������ �� ���� ���� �л��� ���� ����Ŭ ����

3. x�� ��湮
x�� ����Ŭ ����.
x���� ����� �ٽ� x�� ������ �� ���� ���� �л��� ����Ŭ ���� �л����� ����

Ǯ��: https://blog.encrypted.gg/499
*/