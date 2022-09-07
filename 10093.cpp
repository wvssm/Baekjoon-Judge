// Authored by : wvssm
// https://www.acmicpc.net/problem/10093
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b, min, max;
	cin >> a >> b;
	if (a == b || abs(b-a) == 1) cout << 0 << "\n"; 
	else {
		if (a > b) min = b, max = a; // ���� ���� ���ϰ� swap(a,b) �ϱ⵵ ����
		else min = a, max = b;
		
		cout << max - min - 1 << "\n";
		for (long long i = min + 1; i < max; i++) cout << i << " ";
	}
}

// �ð����⵵ : O(N)
// ���� ���ܻ�Ȳ�� �� ��Ƴ��� �Ѵ�.
// 1. A,B�� ���� ���� ���
// 2. A,B�� 1 ���� �� ���
// 3. A�� �� ū ���� ���