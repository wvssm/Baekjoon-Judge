// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/ba53d62b7651443cbf7b2028c28ce197
#include <bits/stdc++.h> 
using namespace std;
#define X first;
#define Y second;
int dist[100002];
int n, k;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	fill(dist, dist + 100001, -1);
	dist[n] = 0;
	queue<int>Q;
	Q.push(n);
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (int nxt : {cur + 1, cur - 1, cur * 2}) { // 이렇게 표현 할 수 있음
			if (nxt < 0 || nxt>100000) continue;
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			Q.push(nxt);
		}
	}
	cout << dist[k];
}
/*
수빈이가 0, 100000 사이에서만 움직인다고 멋대로 가정하고 풀면 안됨
최대 200000까지 갈 수 있음, 근데 100000을 넘기는 자체가 손해, -1 * 2하는게 나음 */