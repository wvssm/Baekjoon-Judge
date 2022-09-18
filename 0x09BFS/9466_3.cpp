//O(N) 바킹독님 풀이
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

		// 1번 경우
		if (state[cur] == CYCLE_IN || state[cur] == NOT_CYCLE_IN) {
			cur = x; // 처음 시작점 담음
			while (state[cur] == VISITED) {
				state[cur] = NOT_CYCLE_IN;
				cur = arr[cur];
			}
			return;
		}

		// 2번 경우
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

		// 3번 경우
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