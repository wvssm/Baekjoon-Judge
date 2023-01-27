#include <bits/stdc++.h>
using namespace std;

int Z(int n, int r, int c) {
	if (n == 0) return 0;
	int half = (1 << n)/2;
	if (r < half && c < half) return Z(n - 1, r, c);
	else if (r < half) return half * half + Z(n - 1, r, c - half);
	else if (c < half) return half * half * 2 + Z(n - 1, r - half, c);
	else return half * half * 3 + Z(n - 1, r - half, c - half);
 }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, r, c;
	cin >> n >> r >> c;
	cout << Z(n, r, c);
}