#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int state[100005];
int n;

const int NOT_VISIT = 0;
const int IN_CYCLE = -1;

void run(int x) {
	int cur = x;
	while (1) {
		state[cur] = x;
		cur = arr[cur];

		// �̹� �湮���� ������ �л��� �������� ���
		if (cur[state] == x) {
			while (cur[state] != IN_CYCLE) {
				state[cur] = IN_CYCLE;
				cur = arr[cur];
			}
			return;
		}

		// ���� �湮���� ������ �л��� �������� ���
		else if(cur[state] != 0) {
			return;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int cnt=0;
		cin >> n;
		fill(state, state + n + 1, 0);

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < n; i++) {
			if (state[i] == NOT_VISIT) run(i);
		}

		for (int i = 0; i < n; i++) {
			if (state[i] != IN_CYCLE) cnt++;
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

-> ���ݸ� �� ����

1. ���� �Ͽ� �湮�� �л� ��湮
-> �������� �湮�� �л��� �ϴ� ����Ŭ ����x
2. �̹� �Ͽ� �湮�� �л� ��湮
2-1. ó�� �л��̶� ����. -> �������� �湮�� �ֵ� �ϴ� ����Ŭ
2-2. ó�� �л��̶� �ٸ���. -> �ٸ� �л����� �ٽ� �ٸ� �л� �� ������ �ϴ� ����Ŭ
*/