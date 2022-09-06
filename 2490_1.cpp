#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int result, input;
	string res = "DCBAE";

	for (int r = 0; r < 3; r++) {
		result = 0;
		for (int c = 0; c < 4; c++) {
			cin >> input;
			result += input;
		}
		cout << res[result] << '\n';
	}
}

// 시간복잡도 : O(N^2)
// 변수 3개로 끝내버림, 메모리 절약
// 배열 필요없이 input으로 모두 받아버리고, 4개의 윳의 합으로 상태구분
// 윳의 합을 index로 사용하여 string의 배열에 값을 가져오는게 충격