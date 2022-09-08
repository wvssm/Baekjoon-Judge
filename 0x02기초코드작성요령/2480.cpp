#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[3];
	int prize;
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	if (a[0] == a[2]) prize = 10000 + a[0] * 1000;
	else if (a[0] == a[1] || a[1] == a[2]) prize = 1000 + a[1] * 100;
	else prize = a[2] * 100;
	cout << prize;
}