#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10], input[10], isused[10];
int st;

void func(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++) cout << input[arr[i]] << ' ';
		cout << '\n';
		return;
	}

	st = 0;
	int tmp = 0; // 중복을 확인할지 임시 변수 (전역변수로 하고 0으로 초기화 하니 답 다르게 남, 중첩으로 갈 때 이동)
	if (cur != 0) st = arr[cur - 1] + 1;
	for (int i = st; i < n; i++) {
		//cout << "****i의 값:" << i << " tmp의 값:" << tmp << " cur의 값:"<<cur<< '\n';
		if (!isused[i] && tmp != input[i]) {
			isused[i] = 1;
			arr[cur] = i;
			tmp = input[i];
			//cout << "i의 값:" << i << " tmp의 값:" << tmp << '\n';
			func(cur + 1);
			isused[i] = 0; // 이후에 for문으로 감, 그래서 새로운 함수에 들어가기전 tmp값을 갖는게 아니라 
			// func(cur+1)에서 변경된 tmp값이 그대로 갖고 있다. 전역변수로 선언하면 그래서 int tmp=0; 이렇게 선언해주어야한다.
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