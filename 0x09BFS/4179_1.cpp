// http://boj.kr/aed4ec552d844acd8853111179d5775d
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[1002];
int dist1[1002][1002]; // 불의 전파 시간
int dist2[1002][1002]; // 지훈이의 이동 시간
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    //dist 전부 -1로 채워주기
    for (int i = 0; i < n; i++) {
        fill(dist1[i], dist1[i] + m, -1);
        fill(dist2[i], dist2[i] + m, -1);
    }
    //board 입력 받기
    for (int i = 0; i < n; i++)
        cin >> board[i];
    //큐를 두개 다른거 사용
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
    // 불에 대한 BFS
    while (!Q1.empty()) {
        auto cur = Q1.front(); Q1.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue; // 벽과 방문한 곳을 제외하고 불
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q1.push({ nx,ny });
        }
    }

    // 지훈이에 대한 BFS
    while (!Q2.empty()) {
        auto cur = Q2.front(); Q2.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) { // 범위를 벗어났다는 것은 탈출에 성공했다는 의미. 큐에 거리 순으로 들어가므로 최초에 탈출한 시간을 출력하면 됨.
                cout << dist2[cur.X][cur.Y] + 1;
                return 0;
            }
            if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue; // 이미 방문했거나, 벽일 때
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue; // 불의 전파 시간을 조건에 추가
            // 이미 지나갔는데(0이상) 안 지난건 아닌 곳(-1이아님)
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q2.push({ nx,ny });
        }
    }
    cout << "IMPOSSIBLE"; // 여기에 도달했다는 것은 탈출에 실패했음을 의미.
}