// Authored by : wvssm
// https://www.acmicpc.net/problem/10093
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b, min, max;
	cin >> a >> b;
	if (a == b || abs(b-a) == 1) cout << 0 << "\n"; 
	else {
		if (a > b) min = b, max = a; // 변수 선언 안하고 swap(a,b) 하기도 가능
		else min = a, max = b;
		
		cout << max - min - 1 << "\n";
		for (long long i = min + 1; i < max; i++) cout << i << " ";
	}
}

// 시간복잡도 : O(N)
// 세부 예외상황을 잘 잡아내야 한다.
// 1. A,B가 같은 값일 경우
// 2. A,B가 1 차이 날 경우
// 3. A가 더 큰 수일 경우