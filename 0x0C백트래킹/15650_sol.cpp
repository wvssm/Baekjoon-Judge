#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int isused[10];

void func(int cur) {
	if (cur == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// 사전식으로 조합 뽑는법, 이전에 사용되지 않는 숫자들을 차례대로 뽑는다.
	// 따라서 뒤의 수는 이전 수 보다 무조건 큰 수들이 오기 때문에 for문을 이전 자리 수보다
	// 큰 수들을 순환시켜야 한다.
	int st = 1;
	if (cur != 0) st = arr[cur - 1] + 1; //이전 자리 값에서 1 더한 값으로 순환해야함
	
	for (int i = st; i <= N; i++) {
		if (isused[i]) {
			arr[cur] = i;
			isused[i] = 1;
			func(cur + 1);
			isused[i] = 0;
		}
	}
}