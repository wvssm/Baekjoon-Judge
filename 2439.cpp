#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) s += "*";
		
		cout.width(n);
		cout << s << "\n";
		s = "";
	}	
}

// c++ 오른쪽 정렬
