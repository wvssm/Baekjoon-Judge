#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, x, ans;
int input[100001], arr[2000001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i]; // 수열 저장
		arr[input[i]] += 1; // 수열 원소 유무 저장
	}
	cin >> x;

	for (int i = 0; i < n; i++) {
		if (x <= input[i]) continue;
		if (arr[x - input[i]] == 1) ans++; // 해당 수열의 원소와 합이 x 되는 원소가 존재하는지 확인
	}
	cout << ans / 2;

	/*
	조건에 해당하는 값이 존재하는지(occur) 확인하고, 그 다음에 occur 표시
	for (int i = 0; i < n; i++) {
		if (x - input[i] > 0 && arr[x - input[i]]) ans++;
		arr[input[i]] = 1;
	}
	cout << ans;
	이렇게 작성하면 숫자쌍의 절반만 남음
	*/
}
// 공간복잡도: O(2000000), 시간복잡도 O(N)