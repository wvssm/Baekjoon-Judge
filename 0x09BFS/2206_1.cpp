#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

char board[1000][1000];
int dist[1000][1000][2];
// dist[x][y][0] : ���� �ϳ��� �μ��� �ʰ� (x,y)���� ���µ� �ɸ��� ���
// dist[x][y][1] : ���� �ϳ��� �μ��� (x,y)���� ���µ� �ɸ��� ���, (x,y)�� ���̶� �μ��� ��� ����
int n, m;

// ���� �Ѵ��� Ȯ��
bool OOB(int x, int y) { 
    return x < 0 || x >= n || y < 0 || y >= m;
}

int bfs() {

    // �Ÿ� -1�� �ʱ�ȭ
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dist[i][j][0] = dist[i][j][1] = -1;

    // ������� �Ÿ� 1�� �ʱ�ȭ
    dist[0][0][0] = dist[0][0][1] = 1;
    queue<tuple<int, int, int>> q;
    q.push({ 0,0,0 }); // �� �ȻѼ� ��� ���� ����
    while (!q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = q.front(); // Q�� front �� ����

        if (x == n - 1 && y == m - 1) return dist[x][y][broken]; // �������̸� return (���� ���� ������ �� return)
        q.pop();
        int nextdist = dist[x][y][broken] + 1; // ���� ���� �Ÿ� ���ϱ�
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (OOB(nx, ny)) continue;
            if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1) { // ���� ����, �湮���� �ʾ�����
                dist[nx][ny][broken] = nextdist; 
                q.push({ nx, ny, broken });
            }
            // (nx, ny)�� �μ��� ���
            if (!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1) { // ���� �ְ�, �湮���� �ʾҰ�, ������ ���� ���� �ʾ�����
                dist[nx][ny][1] = nextdist;
                q.push({ nx, ny, 1 }); 
            }
        }
    }
    return -1; // ���� �������� �������� �ʾ����� -1 ����
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];
    cout << bfs();
    return 0;
}
/*
Ǯ�̹��: ��� ������ ��� ���� ����.
pair�� ������� �ʰ� tuple�� ����Ͽ� ���� �ո��� �ִ� ��츦 1�� ǥ����.
�������� ������ ��� �ߴ���.
�ѽ��ܸ��� ���� ��� ������ ���, ���վ ������ ��츦 ���ʴ�� ť�� ����.*/