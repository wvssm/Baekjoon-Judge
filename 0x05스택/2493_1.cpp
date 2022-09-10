// Authored by : wvssm
// https://www.acmicpc.net/problem/2493
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	stack<pair<int,int>> s;
	vector<int>ans;
	int n, t;

	cin >> n; // 탑의 수 입력

	// 수신하는 탑이 없는 경우 index를 0으로 출력하기 위해 최대높이(10^9)보다 높은 탑 추가
	s.push(make_pair(1000000001, 0)); 

	for (int i= 1; i<= n;i++) {
		cin >> t;
		while (1) {
			if (s.top().first > t) { // 이전 탑이 현재 탑보다 더 높다면
				cout << s.top().second << ' '; // 이전 탑의 인덱스 출력
				s.push(make_pair(t, i)); // 현재 탑 스택에 추가
				break;
			}
			else { // 이전 탑이 현재 탑보다 높지 않다면
				s.pop(); // 이전 탑 삭제
			}
		}
	}
}