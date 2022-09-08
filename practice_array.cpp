#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int sum[100];

int func2(int arr[], int N) {
	for (int i = 0; i < N; i++) sum[arr[i]] += 1;

	for (int i = 1; i < 50; i++) {
		if (sum[i] == 1 && sum[100 - i] == 1) return 1;
	}
	if (sum[50] == 2) return 1;
	return 0;
}

// BaaaaaaaarkingDog´Ô Ç®ÀÌ
int func3(int arr[], int N) {
	int occur[101] = {};
	for (int i = 0; i < N; i++) {
		if (occur[100 - arr[i]]) return 1;
		occur[arr[i]] = 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a[5] = { 1,2,98,3,5 };
	cout << func2(a, 5) << "\n";
}
