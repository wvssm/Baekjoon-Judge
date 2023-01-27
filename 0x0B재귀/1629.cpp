#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b, c, ans;

ll func(ll b) { // 인자 값도 long long으로 선언하는 것 잊지 않기
	if (b == 1) return a % c;

	ans = func(b / 2);
	ans = ans * ans % c; // 풀이 중에 값이 long long 값을 초과하지 않도록 식 적기 
	if (b % 2 == 0) {
		return ans;
	}
	else {
		return ans = ans * a % c;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> c;
	cout << func(b);
}