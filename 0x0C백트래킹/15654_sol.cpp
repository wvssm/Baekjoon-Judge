// 백준 15654 N과 M (5)
// 원소를 직접 출력할 배열에 넣은 것이 아니라
// 출력할 인덱스 번호를 배열에 저장해놓고
// 인덱스에 따라 입력 배열에 간접 접근
#include <bits/stdc++.h>
using namespace std;

int n, m;
int input[10];
int arr[10];
int isused[10];

void func(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++) {
			cout << input[arr[i]] << ' '; // 배열 자체를 인덱스로 사용 가능
			// 인덱스를 배치해서 그 안의 값을 끌어내기
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!isused[i]) { // 1,2,3,4로 출력할 인덱스 숫자 배치하기
			arr[cur] = i;
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