// Authored by : haneulkimdev
// Co-authored by : BaaaaaaaaaaarkingDog
// https://www.acmicpc.net/problem/1874
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int>s;
	int n, t, cnt = 1;
	string ans = "";
	cin >> n;

	while (n--) {
		cin >> t;
		while (cnt<=t) {
			s.push(cnt++); // �ʿ��� ���� ��ŭ �Է�
			ans += "+\n";
		}
		if (s.top() != t) { // stack.top()�� �ٸ��ٸ� ���� ������ �ƴ�
			cout << "NO";
			return 0;
		}

		s.pop();
		ans += "-\n";
	}
	cout << ans;
}

/* �� ���ҵ� ��� pop�ؾߵǱ� ������
������ ���� �ʿ���� �� �������� ��ġ�ϸ� ��*/ 