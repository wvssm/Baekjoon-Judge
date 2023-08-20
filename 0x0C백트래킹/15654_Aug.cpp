// น้มุ 15654 Nฐ๚ M (5)
#include <bits/stdc++.h>
using namespace std;

int n, m;
int input[10];
int arr[10];
int isused[10];

void func(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!isused[i]) {
			arr[cur] = input[i];
			isused[i] = 1;
			func(cur + 1);
			isused[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> input[i];
	sort(input, input + n);
	func(0);
}