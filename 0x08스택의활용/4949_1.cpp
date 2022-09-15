#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while(1) {
		stack<char>s;
		string str;
		getline(cin, str); // 공백까지 string 입력 받기
		int f = 0; // 틀린지 아닌지 확인하는 변수

		// 마침표만 찍혀 있으면 종료
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
4949.cpp와 알고리즘은 같지만 좀 더 간결하게 작성
*/