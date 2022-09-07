// https://www.acmicpc.net/problem/2445
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n-1; i++) {
		for (int j = 0; j < i; j++) cout << '*';
		for (int j = 0; j < 2 * (n - i); j++) cout << ' ';
		for (int j = 0; j < i; j++) cout << '*';
		cout << "\n";
	}

	for (int i = 0; i < 2 * n; i++) cout << "*";
	cout << "\n";

	for(int i=n-1;i>0;i--){
		for (int j = 0; j < i; j++) cout << '*';
		for (int j = 0; j < 2 * (n - i); j++) cout << ' ';
		for (int j = 0; j < i; j++) cout << '*';
		cout << "\n";
	}
}