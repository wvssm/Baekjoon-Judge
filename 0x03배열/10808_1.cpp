//https://www.acmicpc.net/problem/10808
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int arr[26];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 배열이 지역변수 였다면
	// int arr[26] = {} 혹은 fill(arr, arr + 26, 0);

	string input;
	cin >> input;
	
	for (auto c : input) arr[c - 'a']++; // 아스키코드 이용, a일 경우 0됨

	for (auto &i : arr) cout << i << ' ';
}
// 시간 복잡도 : O(N)