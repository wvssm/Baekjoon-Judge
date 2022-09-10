// Authored by : twinkite
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/44465623025e452bba5feb80b0b0e60e
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N;
stack<pair<int, int>> tower;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	tower.push({ 1000000001,0 }); // {a,b} �ٷ� pair ���� �� ����
	for (int i = 1; i <= N; i++) {
		int height;
		cin >> height;
		while (tower.top().X < height) tower.pop(); // ���� ž���� ���� ž ���� ������ pop();
		cout << tower.top().Y << ' ';
		tower.push({ height, i });
	}
}