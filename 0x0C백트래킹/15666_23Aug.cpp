// ���� 15666�� N�� M (12)
#include <bits/stdc++.h>
using namespace std;

int n, m, st;
int arr[10], input[10], isused[10];

void func(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++) {
			cout << input[arr[i]] << ' ';
		}
		cout << '\n';
		return;
	}

	st = 0;
	if (cur != 0) st = arr[cur - 1];
	int tmp = 0;
	for (int i = st; i < n; i++) {
		if (tmp != input[i]) {
			arr[cur] = i;
			tmp = input[i];
			func(cur + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input, input + n);
	func(0);
}