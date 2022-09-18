// 내가 스스로 구현했지만 출력이 안나옴, 망함
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
		// 첫번째 경우
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

		// 3번째 경우
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
	// 2번째 경우
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
사이클에 포함되지 않은 원소의 개수를 출력하는 문제

O(N)풀이: 임의의 원소 x에서 N번 만큼 칸 이동

1. 사이클에 포함된 학생 or 사이클에 포함되지 않은 학생 재방문
x는 사이클에 포함x, 이제까지 방문한 학생들 싹다 사이클 포함 x

2. x가 아닌 다른 방문한 학생 y 재방문
x는 사이클 포함x, y는 사이클 포함
y에서 출발해 다시 y까지 도달할 때 까지 만난 학생들 전부 사이클 포함

3. x를 재방문
x는 사이클 포함.
x에서 출발해 다시 x에 도달할 때 까지 만난 학생들 사이클 포함 학생으로 만듦

풀이: https://blog.encrypted.gg/499
*/