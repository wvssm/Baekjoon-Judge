#include<bits/stdc++.h>
using namespace std;
int num;

void underbar(int r) {
	for (int i = 0; i < r; i++) {
		cout << "____";
	}
}

void teacher(int n) {
	if (n == 0) {
		underbar(num - n);
		cout << "\"����Լ��� ������?\"\n";
		underbar(num - n);
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		underbar(num - n);
		cout << "��� �亯�Ͽ���.\n";
		return;
	}
	underbar(num - n);
	cout  << "\"����Լ��� ������?\"\n";
	underbar(num - n);
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	underbar(num - n);
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	underbar(num - n);
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
	teacher(n - 1);
	underbar(num - n);
	cout << "��� �亯�Ͽ���.\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> num;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	teacher(num);
}

// ���� ǥ���� ¥������.
// '�׷��� ��� ��' �տ� ������� ���ؼ� Ʋ�ȴ�.