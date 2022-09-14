#include<bits/stdc++.h>
using namespace std;

int back;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> dq;
	int T, n, e=0;
	string p, numbers;
	
	cin >> T;
	while (T--) {
		back = 0;
		e = 0;
		cin >> p;
		cin >> n;
		cin >> numbers;

		numbers = numbers.substr(1, numbers.length() - 2);
		//cout << numbers;
		istringstream ss(numbers);
		string numbers1;
		while (getline(ss, numbers1, ',')) {
			dq.push_back(stoi(numbers1));
		}
		//for (auto i : dq) cout << i << '\n';
		for (auto i : p) {
			if (i == 'R') {
				if (back == 1) back = 0;
				else back = 1;
			}
			else if (i == 'D') {
				if (dq.empty()) {
					cout << "error\n";
					e = 1;
					break;
				}
				else if (back == 0) dq.pop_front();
				else dq.pop_back();

			}
		}
		if (dq.empty() && e == 1) {
			continue;
		}
		cout << '[';
		if (back == 0) {
			while (!dq.empty()) {
				if(dq.size()==1) cout << dq.front();
				else cout << dq.front() << ',';
				dq.pop_front();
			}
		}
		else if (back == 1) {
			while (!dq.empty()) {
				if (dq.size() == 1) cout << dq.back();
				else cout << dq.back() << ',';
				dq.pop_back();
			}
		}
		cout << "]\n";
		back = 0;
		e = 0;
	}
}

// ���� �ʱ�ȭ, back, error
// �׸��� ���� N���� ���� T���� ����, ������ �� ���ϴ��� ��Ȯ�� �˱�
// []�� ��� ����
// �Է��� �� parsing�� ��Ȯ�ϰ� ���� Ȯ��