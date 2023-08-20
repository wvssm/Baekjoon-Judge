// ���� 15650 next_permutation ����ؼ� ǯ
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10] = { 1,1,1,1,1,1,1,1,1,1};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		arr[i] = 0;
	}

	do {
		for (int i = 0; i < n; i++) {
			if (arr[i] == 0) {
				cout << i+1 << ' ';
			}
		}
		cout << '\n';
	} while (next_permutation(arr, arr + n));
}

/**
int N, M;
vector<int> a;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) a.push_back(i < M ? 0 : 1); 
	// �迭 ��� ���� �̿�, for �� �̿��ؼ� 0,1 �ʱ�ȭ ����

	do {
		for (int i = 0; i < N; i++) {
			if (a[i] == 0) cout << i + 1 << ' ';
		}
		cout << '\n';
	} while (next_permutation(a.begin(), a.end()));
	// ������ �� ó��, �� ���ϴ� ���
}
*/