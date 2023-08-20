#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int isused[10]; // 이전에 같은 수가 사용되었는지
int isused_2[50000]; // 두 수의 조합이 사용되었는지 확인
// 모든 조합의 곱만 사용했을 때는 (2,3,4)과 (1,4,6)이 구분이 안됨, 그래서 조합의 합과 곱 둘다 확인하기로 함, 조합의 곱+조합의 합*100이 있는지 isused를 통해 확인

void func(int cur,int mul, int plus) {
	// 모든 단계가 완성되었을 때, 이전에 이런 수의 조합이 없었는지 확인 (수의 곱 + 수의 합*100 값으로 확인)
	if (cur == M) {
		if (!isused_2[mul+plus*100]) {
			for (int i = 0; i < M; i++) {
				cout << arr[i] << ' ';
			}
			cout << '\n';
			isused_2[mul+plus*100] = 1;
			return;
		}
	}

	// 단계별로 숫자 뽑기
	for (int i = 0; i < N; i++) {
		if (!isused[i]) {
			isused[i] = 1;
			arr[cur] = i + 1;
			func(cur + 1, mul * arr[cur],plus+arr[cur]);
			isused[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	func(0, 1, 0);
}