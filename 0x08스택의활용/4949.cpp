// Authored by : wvssm
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string sen;
	int err = 0;

	while (1) {
		stack<char>stk;
		err = 0;
		getline(cin, sen);
		if (sen == ".") break;
		for (auto i : sen) {
			if (i == '[') stk.push(i);
			else if (i == '.') break;
			else if (i == '(') stk.push(i);
			else if (i == ')') {
				if(!stk.empty()){
					if (stk.top() == '(') stk.pop();
					else {
						err = 1;
						break;
					}
				}
				else {
					err = 1;
					break;
				}
			}
			else if (i == ']') {
				if (!stk.empty()) {
					if (stk.top() == '[') stk.pop();
					else {
						err = 1;
						break;
					}
				}
				else {
					err = 1;
					break;
				}
			}
		}
		if (stk.empty()!=1 || err==1) cout << "no\n";
		else cout << "yes\n";
	}
}

/* 디버깅 
스택이 매 회 초기화 되는지 확인하기
top 확인할 때 stack이 항상 비어있지 않은지 확인하기
예외처리 잘하기, if 했으면 else도 처리하기
*/