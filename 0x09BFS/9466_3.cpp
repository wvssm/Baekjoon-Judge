//O(N) ��ŷ���� Ǯ��
#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int n;
int state[100005];

const int NOT_VISITED = 0;
const int VISITED = 1;
const int CYCLE_IN = 2;
const int NOT_CYCLE_IN = 3;

void run(int x) {
	int cur = x;
	while (true) {
		state[cur] = VISITED;
		cur = arr[cur];

		// 1�� ���
		if (state[cur] == CYCLE_IN || state[cur] == NOT_CYCLE_IN) {
			cur = x; // ó�� ������ ����
			while (state[cur] == VISITED) {
				state[cur] = NOT_CYCLE_IN;
				cur = arr[cur];
			}
			return;
		}

		// 2�� ���
		if (state[cur] == VISITED && cur != x) {
			while (state[cur] != CYCLE_IN) {
				state[cur] = CYCLE_IN;
				cur = arr[cur];
			}
			cur = x;
			while (state[cur] != CYCLE_IN) {
				state[cur] = NOT_CYCLE_IN;
				cur = arr[cur];
			}
			return;
		}

		// 3�� ���
		if (state[cur] == VISITED && cur == x) {
			while (state[cur] != CYCLE_IN) {
				state[cur] = CYCLE_IN;
				cur = arr[cur];
			}
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 0;
	cin >> t;
	while (t--) {
		int cnt = 0;
		cin >> n;
		fill(state, state + n + 1, 0);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < n; i++) {
			if(state[i]==NOT_VISITED) run(i);
		}

		for (int i = 0; i < n; i++) {
			if (state[i] == NOT_CYCLE_IN) cnt++;
		}
		cout << cnt << '\n';
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