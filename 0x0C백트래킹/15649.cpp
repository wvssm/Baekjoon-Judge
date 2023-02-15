// 백준 15649 - N과 M (1)
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int isused[10];

void func(int k) {
	// 순열이 완성되면 출력하기
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!isused[i]) { // 사용되지 않았으면
			isused[i] = 1; // k번째 순서의 숫자로 사용
			arr[k] = i; // k번째에 숫자 저장 
			func(k + 1); // k+1번째 순서의 숫자 결정
			isused[i] = 0;
		}
	 }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);
}
