// 백준 15650 next_permutation 사용해서 풂
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
	// 배열 대신 벡터 이용, for 문 이용해서 0,1 초기화 해줌

	do {
		for (int i = 0; i < N; i++) {
			if (a[i] == 0) cout << i + 1 << ' ';
		}
		cout << '\n';
	} while (next_permutation(a.begin(), a.end()));
	// 벡터일 때 처음, 끝 정하는 방법
}
*/