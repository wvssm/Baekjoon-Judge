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

		// 이번 방문에서 지나간 학생에 도달했을 경우
		if (cur[state] == x) {
			while (cur[state] != IN_CYCLE) {
				state[cur] = IN_CYCLE;
				cur = arr[cur];
			}
			return;
		}

		// 이전 방문에서 지나간 학생에 도달했을 경우
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

-> 조금만 더 간결

1. 이전 턴에 방문한 학생 재방문
-> 이제까지 방문한 학생들 싹다 사이클 포함x
2. 이번 턴에 방문한 학생 재방문
2-1. 처음 학생이랑 같다. -> 이제까지 방문한 애들 싹다 사이클
2-2. 처음 학생이랑 다르다. -> 다른 학생부터 다시 다른 학생 될 때까지 싹다 사이클
*/