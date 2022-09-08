#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int d[10]={};
	while (n > 0) {
		d[n % 10] += 1;
		n /= 10;
	}

	int index = 0;
	int max = 0;
	if ((d[6] + d[9]) % 2 == 1) max = (d[6] + d[9]) / 2 + 1;
	else max = (d[6] + d[9]) / 2;
	// d[6] = (int)ceil((a[6]+a[9])/(double)2);
	// d[9] = 0; 

	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) continue;
		if (d[i] > max) max = d[i];
	}

	cout << max;
}