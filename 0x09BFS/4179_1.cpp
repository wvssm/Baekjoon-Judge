// http://boj.kr/aed4ec552d844acd8853111179d5775d
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[1002];
int dist1[1002][1002]; // ���� ���� �ð�
int dist2[1002][1002]; // �������� �̵� �ð�
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    //dist ���� -1�� ä���ֱ�
    for (int i = 0; i < n; i++) {
        fill(dist1[i], dist1[i] + m, -1);
        fill(dist2[i], dist2[i] + m, -1);
    }
    //board �Է� �ޱ�
    for (int i = 0; i < n; i++)
        cin >> board[i];
    //ť�� �ΰ� �ٸ��� ���
    queue<pair<int, int> > Q1;
    queue<pair<int, int> > Q2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'F') {
                Q1.push({ i,j });
                dist1[i][j] = 0;
            }
            if (board[i][j] == 'J') {
                Q2.push({ i,j });
                dist2[i][j] = 0;
            }
        }
    }
    // �ҿ� ���� BFS
    while (!Q1.empty()) {
        auto cur = Q1.front(); Q1.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue; // ���� �湮�� ���� �����ϰ� ��
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q1.push({ nx,ny });
        }
    }

    // �����̿� ���� BFS
    while (!Q2.empty()) {
        auto cur = Q2.front(); Q2.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) { // ������ ����ٴ� ���� Ż�⿡ �����ߴٴ� �ǹ�. ť�� �Ÿ� ������ ���Ƿ� ���ʿ� Ż���� �ð��� ����ϸ� ��.
                cout << dist2[cur.X][cur.Y] + 1;
                return 0;
            }
            if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue; // �̹� �湮�߰ų�, ���� ��
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue; // ���� ���� �ð��� ���ǿ� �߰�
            // �̹� �������µ�(0�̻�) �� ������ �ƴ� ��(-1�̾ƴ�)
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q2.push({ nx,ny });
        }
    }
    cout << "IMPOSSIBLE"; // ���⿡ �����ߴٴ� ���� Ż�⿡ ���������� �ǹ�.
}