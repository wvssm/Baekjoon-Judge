#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

char board[1000][1000];
int dist[1000][1000][2];
// dist[x][y][0] : 벽을 하나도 부수지 않고 (x,y)까지 오는데 걸리는 비용
// dist[x][y][1] : 벽을 하나만 부수고 (x,y)까지 오는데 걸리는 비용, (x,y)가 벽이라서 부수는 경우 포함
int n, m;

// 범위 넘는지 확인
bool OOB(int x, int y) { 
    return x < 0 || x >= n || y < 0 || y >= m;
}

int bfs() {

    // 거리 -1로 초기화
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dist[i][j][0] = dist[i][j][1] = -1;

    // 출발지의 거리 1로 초기화
    dist[0][0][0] = dist[0][0][1] = 1;
    queue<tuple<int, int, int>> q;
    q.push({ 0,0,0 }); // 벽 안뿌순 경우 먼저 시작
    while (!q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = q.front(); // Q의 front 값 받음

        if (x == n - 1 && y == m - 1) return dist[x][y][broken]; // 도착점이면 return (제일 빨리 도착한 값 return)
        q.pop();
        int nextdist = dist[x][y][broken] + 1; // 다음 지점 거리 구하기
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (OOB(nx, ny)) continue;
            if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1) { // 벽이 없고, 방문하지 않았으면
                dist[nx][ny][broken] = nextdist; 
                q.push({ nx, ny, broken });
            }
            // (nx, ny)를 부수는 경우
            if (!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1) { // 벽이 있고, 방문하지 않았고, 이전에 벽을 뚫지 않았으면
                dist[nx][ny][1] = nextdist;
                q.push({ nx, ny, 1 }); 
            }
        }
    }
    return -1; // 최종 목적지에 도달하지 않았으면 -1 리턴
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
풀이방법: 모든 가능한 경우 벽을 뚫음.
pair을 사용하지 않고 tuple을 사용하여 벽이 뚫린적 있는 경우를 1로 표시함.
목적지에 도달한 경우 중단함.
한스텝마다 벽이 없어서 가능한 경우, 벽뚫어서 가능한 경우를 차례대로 큐에 담음.*/