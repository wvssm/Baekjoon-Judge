// Authored by : wvssm
// https://www.acmicpc.net/problem/2493
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	stack<pair<int,int>> s;
	vector<int>ans;
	int n, t;

	cin >> n; // ž�� �� �Է�

	// �����ϴ� ž�� ���� ��� index�� 0���� ����ϱ� ���� �ִ����(10^9)���� ���� ž �߰�
	s.push(make_pair(1000000001, 0)); 

	for (int i= 1; i<= n;i++) {
		cin >> t;
		while (1) {
			if (s.top().first > t) { // ���� ž�� ���� ž���� �� ���ٸ�
				cout << s.top().second << ' '; // ���� ž�� �ε��� ���
				s.push(make_pair(t, i)); // ���� ž ���ÿ� �߰�
				break;
			}
			else { // ���� ž�� ���� ž���� ���� �ʴٸ�
				s.pop(); // ���� ž ����
			}
		}
	}
}