#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10], input[10], isused[10];
int st;

void func(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++) cout << input[arr[i]] << ' ';
		cout << '\n';
		return;
	}

	st = 0;
	int tmp = 0; // �ߺ��� Ȯ������ �ӽ� ���� (���������� �ϰ� 0���� �ʱ�ȭ �ϴ� �� �ٸ��� ��, ��ø���� �� �� �̵�)
	if (cur != 0) st = arr[cur - 1] + 1;
	for (int i = st; i < n; i++) {
		//cout << "****i�� ��:" << i << " tmp�� ��:" << tmp << " cur�� ��:"<<cur<< '\n';
		if (!isused[i] && tmp != input[i]) {
			isused[i] = 1;
			arr[cur] = i;
			tmp = input[i];
			//cout << "i�� ��:" << i << " tmp�� ��:" << tmp << '\n';
			func(cur + 1);
			isused[i] = 0; // ���Ŀ� for������ ��, �׷��� ���ο� �Լ��� ������ tmp���� ���°� �ƴ϶� 
			// func(cur+1)���� ����� tmp���� �״�� ���� �ִ�. ���������� �����ϸ� �׷��� int tmp=0; �̷��� �������־���Ѵ�.
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input, input + n);
	func(0);
}