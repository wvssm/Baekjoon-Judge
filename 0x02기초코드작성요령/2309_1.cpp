// Authored by : wogha95
// http://boj.kr/ca6967094ffc44a9887b331a045d8509
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int num[9], result[7];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	 
	for (int i = 0; i < 9; i++) cin >> num[i];

	int total;
	for (int a = 0; a < 8; a++) {
		total = 0;

		for (int b = a + 1; b < 9; b++) {
			total = 0;

			for (int c = 0, i = 0; c < 9; c++) if (c != a && c != b) result[i++] = num[c];
			for (auto i : result) total += result[i];

			if (total == 100) break;
		}
		if (total == 100) break;
	}

	sort(result, result + 7);
	for (int i = 0; i < 7; i++) cout << result[i] << "\n";
}

// 2개 제외하고 가능한 7난쟁이의 경우의 수 중에 합이 100 되는 것을 찾음
// 시간복잡도 O(N^3)