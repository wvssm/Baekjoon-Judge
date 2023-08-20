#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	int gap = n - m;
	int divide = 1;
	int cnt = 0;

	if (gap > 1) {
		for (int j = 1; j <= gap; j++) {
			divide *= j;
		}
	}


	do {
		if (cnt % divide == 0) {
			for (int i = 0; i < m; i++) {
				cout << arr[i] << ' ';
			}
			cout << '\n';
		}
		cnt++;
	} while (next_permutation(arr, arr + n));

}