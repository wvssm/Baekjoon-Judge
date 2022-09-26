// Authored by : std-freejia
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/f04bee3141834b83b6d1e0a6cd8c59b6
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m, year;
int area[303][303];
int vis[303][303];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

bool check(int i, int j) {
	return (i >= 0 || i < n || j >= 0 || j < m);
}

void initvis() {
	for (int i = 0; i < n; i++) fill(vis[i], vis[i] + m, 0);
}

void melting() {
	int zero[303][303] = { 0 }; // ��� ���� ���� �迭
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (area[i][j] == 0) continue;
			for (int dir = 0; dir < 4; dir++) { // �ֺ��� 0�� ������ ����
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (check(nx, ny) && area[nx][ny] == 0)zero[i][j]++; // ���� ���� ���� ����
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			area[i][j] = max(0, area[i][j] - zero[i][j]); // ���� ���
		}
	}
}

// 0 : ������ �� ����, 1 : ���� �� ����, 2 : �и���
int status() {

	// ���� �� ������ Ȯ��
	int x = -1, y = -1;
	int cnt1 = 0; // ������ ����
	// ������ �����ִ� �ƹ� ĭ�̳� ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (area[i][j]) {
				x = i;
				y = j;
				cnt1++;
			}
		}
	}
	if (cnt1 == 0) return 0; // ������ �����ִ� ĭ�� ����
	
	// ��� ���� ����
	int cnt2 = 0; // (x, y)�� �پ��ִ� ������ ��
	queue<pair<int, int>> q;
	vis[x][y] = 1; // ���� ��ġ �湮
	q.push({ x, y });
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		cnt2++;
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (!check(nx, ny) || vis[nx][ny] == 1 || area[nx][ny] <= 0) continue; // ���� ����, ù �湮, �̵� ���� üũ(�������� üũ)
			vis[nx][ny] = 1; // �湮 ǥ��
			q.push({ nx, ny }); // �̵�
		}
	}
	if (cnt1 == cnt2) return 1; // ��ü ������ ���� (x, y)�� �پ��ִ� ������ ���� ��ġ�ϹǷ� ���� �� ����
	return 2;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> area[i][j];
		}
	}

	while (true) {
		year++; // 1�� �߰�
		melting(); // ���� ���̱� (for�� 2�� ������)
		initvis(); // �湮 �迭 �ʱ�ȭ (1.�ٳ����� Ȯ��(for��), 2. ����� Ȯ��(bfs))
		int check = status(); // ������ ���� Ȯ�� (�� ������, �� ��� ����)
		if (check == 0) {
			cout << 0;
			return 0;
		}
		else if (check == 1) continue; // ���� �� ����
		else break; // check = 2, �и���
	}
	cout << year;
	return 0;
}

/*
�� �ڵ�� O(NM * year)�� ����. �־��� �����͸� �־ year�� �뷫 500 ���Ͽ��� �ð� �ʰ��� �߻����� ������
������ �ϱ� ���� �� �ڵ��� �ð����⵵�� ������, year�� � ��쿡 ���� Ŭ��, �� ��� year�� ������
����غ� �ʿ䰡 �ִ�.
100ms Ǯ��
*/