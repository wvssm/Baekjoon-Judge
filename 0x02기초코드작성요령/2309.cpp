// Authored by : wvssm
// https://www.acmicpc.net/problem/2309
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[9], sum=0, remain=0;
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		sum += a[i];
	}

	sort(a, a + 9); // 오름차순 정렬

	remain = sum - 100; // 100과 차이값 입력
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = i + 1; j < 9; j++) {
			if (a[i] + a[j] == remain) break; // 차이값과 합이 같은 두 원소 찾기
		}
		if (a[i] + a[j] == remain) break;
	}

	for (int k = 0; k < 9; k++) {
		if (k == i || k == j) continue; // 두 원소 제외하고 전부 출력
		cout << a[k] << "\n";
	}
}

// 두 원소의 합이 (전체합-100) 과 같은 두 원소를 찾아 나머지 7원소 출력
// 시간복잡도 O(N^2)
