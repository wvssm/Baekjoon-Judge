// Authored by : OceanShape
// https://www.acmicpc.net/problem/1158
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N, K, len = 0;

// ����Ʈ���� ���� ���/���� ��带 ����Ű�� ����
int pre[5001];
int nxt[5001];
// ���Ǫ�� ������ �����ϴ� ����
vector<int>v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;

	// ���� ���� ����Ʈ ����
	// �� ó�� ���� ������ ��尡 ���θ� ����Ű���� ����
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

	// �似Ǫ�� ���� ���
	cout << "<";
	for (size_t i = 0; i < v.size(); ++i) {
		cout << v[i];
		if (i != v.size() - 1)cout << ", ";
	}
	cout << ">";
}

// �迭 2���� ���� ���Ḯ��Ʈ ����, �� ������ ���� vector ���