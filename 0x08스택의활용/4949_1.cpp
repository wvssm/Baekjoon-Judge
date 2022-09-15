#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while(1) {
		stack<char>s;
		string str;
		getline(cin, str); // ������� string �Է� �ޱ�
		int f = 0; // Ʋ���� �ƴ��� Ȯ���ϴ� ����

		// ��ħǥ�� ���� ������ ����
		if (str.compare(".") == 0) return 0;

		for (auto p : str) {
			if (p == '(' || p == '[') s.push(p);
			else if (p == ')' || p == ']') {
				if (s.empty() || (s.top() == '(' && p != ')') || (s.top() == '[' && p != ']')) {
					f = 1;
					break;
				}
				else s.pop();
			}
		}
		if (f || !s.empty()) cout << "no";
		else cout << "yes";
		cout << '\n';
	}
}

/*
4949.cpp�� �˰����� ������ �� �� �����ϰ� �ۼ�
*/