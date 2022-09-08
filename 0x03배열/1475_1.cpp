#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// ans=1로 두어 n=0일 때에 대한 예외처리가 가능함
	int n, a[10] = {}, ans = 1;
	cin >> n;

	while (n) {
		a[n % 10]++;
		n /= 10;
	}

	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9)continue;
		ans = max(ans, (a[6] + a[9] + 1) / 2); // ceil를 구하기 위해 1 더하기
		cout << ans;
	}
}