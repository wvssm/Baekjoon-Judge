#include <bits/stdc++.h>
using namespace std;

void fibo(int start, int end, int num) {
	if (num == 1) {
		cout << start << ' ' << end << '\n'; // 가장 위에 있는 원반 이동
		return;
	}
	fibo(start, 6 - start - end, num - 1);
	cout << start << ' ' << end << '\n'; // 맨 아래에 있는 것 이동
	fibo(6-start-end, end, num - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	cout << (1 << num) - 1 << '\n';
	fibo(1, 3, num);
}

/*
귀납법으로 생각하라고 했지만
실제 구현할 때는 출력을 나타날 때 헷갈려서
절차적으로 원반이 2개 있는 경우를 생각해보면서 문제를 풀었다.
*/