//https://www.acmicpc.net/problem/10808
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int arr[26];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// �迭�� �������� ���ٸ�
	// int arr[26] = {} Ȥ�� fill(arr, arr + 26, 0);

	string input;
	cin >> input;
	
	for (auto c : input) arr[c - 'a']++; // �ƽ�Ű�ڵ� �̿�, a�� ��� 0��

	for (auto &i : arr) cout << i << ' ';
}
// �ð� ���⵵ : O(N)