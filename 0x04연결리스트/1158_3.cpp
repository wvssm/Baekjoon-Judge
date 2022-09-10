// Authored by : seondal
// Co-authored by : BaaaaaaaaaaarkingDog
// https://www.acmicpc.net/problem/1158
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int>V, ans;
	for (int i = 1; i <= n; i++) V.push_back(i); //N
	
	for (int i = 0; ans.size() < n; i++) { // ���� ���Ϳ� n���� ���Ұ� ���̸� ����
		if (i % k == k - 1) ans.push_back(V[i]); 
		else V.push_back(V[i]);
	}

	cout << "<";
	for (int i = 0; i < n; i++) {
		if (i == n - 1) cout << ans[i]; // ������ ���Ҵ� , ���� ���
		else cout << ans[i] << ", ";
	}
	cout << '>';
}

/*
STL vector�� �̿��� Ǯ��
�� ���� ���� ���ŵ��� ���� ���Ҵ� ���� �ڷ� ������(V.push_back(V[i]))
���ŵǴ� ���Ҵ� ans�� �����ϰ� �ִٰ� �� ä������ ���.
���� ���⵵�� O((K-1)*N + N)�̶�� ������ ����.
*/