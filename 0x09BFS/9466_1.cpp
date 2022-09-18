// 바킹독님 예시코드, O(N^2)이라 시간초과
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
		// now = board[now] 이렇게 써도 됨
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
사이클에 포함되지 않은 원소의 개수를 출력하는 문제
O(N^2)풀이: 임의의 원소에서 N번 만큼 이동
칸 이동하는 동안 자신과 똑같은 원소를 지나지 않으면 cycle이 아닌 원소
사이클에 포함되어 있으면 N칸 이동하는 동안 자기 자신을 반드시 지나게 됨

시간초과 나는 풀이
*/