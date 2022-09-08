// https://www.acmicpc.net/problem/10804
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

stack<int> stk;
int card[21];

// STL stack�� �̿��� flip
void flip(int a, int b) {
	for (int i = a; i <= b; i++) {
		stk.push(card[i]);
	}

	int num = a;
	while (!stk.empty()) {
		card[num] = stk.top();
		stk.pop();
		num++;
	}
}

// STL swap�� �̿��� flip2
void flip2(int a, int b) {
	for (int i = 0; i < (b - a)/ 2 + 1; i++) {
		swap(card[a + i], card[b - i]);
	}
}

// STL reverse �̿��ϱ�
// reverse(card+a, card+b+1); card[a]���� card[b]���� reverse

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//ī�� ä���ֱ�
	for (int i = 1; i <= 20; i++) card[i] = i;

	int start, end;
	for (int i = 0; i < 10; i++) {
		cin >> start >> end;
		if (start == end) continue;
		flip2(start, end);
	}

	for (int i = 1; i <= 20; i++) cout << card[i] << " ";
}