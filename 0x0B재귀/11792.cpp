#include <bits/stdc++.h>
using namespace std;

void fibo(int start, int end, int num) {
	if (num == 1) {
		cout << start << ' ' << end << '\n'; // ���� ���� �ִ� ���� �̵�
		return;
	}
	fibo(start, 6 - start - end, num - 1);
	cout << start << ' ' << end << '\n'; // �� �Ʒ��� �ִ� �� �̵�
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
�ͳ������� �����϶�� ������
���� ������ ���� ����� ��Ÿ�� �� �򰥷���
���������� ������ 2�� �ִ� ��츦 �����غ��鼭 ������ Ǯ����.
*/