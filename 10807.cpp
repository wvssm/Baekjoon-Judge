// https://www.acmicpc.net/problem/10807
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int a[201];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, v, t;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> t;
		a[t + 100] += 1;
	}

	cin >> v;
	cout << a[v + 100];
}