// Authored by : OceanShape
// https://www.acmicpc.net/problem/1158
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N, K, len = 0;

// 리스트에서 이전 노드/다음 노드를 가리키는 변수
int pre[5001];
int nxt[5001];
// 요새푸스 순열을 저장하는 변수
vector<int>v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;

	// 원형 연결 리스트 생성
	// 맨 처음 노드와 마지막 노드가 서로를 가리키도록 지정
	for (int i = 1; i < N; i++) {
		pre[i] = (i == 1) ? N : i - 1;
		nxt[i] = (i == N) ? 1 : i + 1;
		++len;
	}

	int i = 1;
	for (int cur = 1; len != 0; cur = nxt[cur]) {
		if (i == K) {
			nxt[pre[cur]] = nxt[cur];
			pre[nxt[cur]] = pre[cur];
			v.push_back(cur);
			int i = 1;
			len--;
		}
		else ++i;
	}

	// 요세푸스 순열 출력
	cout << "<";
	for (size_t i = 0; i < v.size(); ++i) {
		cout << v[i];
		if (i != v.size() - 1)cout << ", ";
	}
	cout << ">";
}

// 배열 2개로 원형 연결리스트 구현, 답 저장을 위해 vector 사용