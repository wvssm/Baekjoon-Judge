#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b, c, ans;

ll func(ll b) { // ���� ���� long long���� �����ϴ� �� ���� �ʱ�
	if (b == 1) return a % c;

	ans = func(b / 2);
	ans = ans * ans % c; // Ǯ�� �߿� ���� long long ���� �ʰ����� �ʵ��� �� ���� 
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