#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num) {
    // 추가할 노드
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];

    // 추가 노드 앞
    nxt[addr] = unused;

    // 추가 노드 뒤
    if(nxt[addr]!=-1) pre[nxt[unused]] = unused; // 뒤에 노드가 없을 수도 있음, 마지막 위치에 insert
    unused++;
}

void erase(int addr) {
    // 삭제 노드 앞
    nxt[pre[addr]] = nxt[addr];

    // 삭제 노드 뒤
    // 맨 마지막 원소를 삭제할 경우도 생각, pre[-1]가 되지 않도록 설정
    pre[nxt[addr]] = pre[addr];
}

void traverse() {
    int cur = nxt[0];
    while (cur != -1) {
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}

void insert_test() {
    cout << "****** insert_test *****\n";
    insert(0, 10); // 10(address=1)
    traverse();
    insert(0, 30); // 30(address=2) 10
    traverse();
    insert(2, 40); // 30 40(address=3) 10
    traverse();
    insert(1, 20); // 30 40 10 20(address=4)
    traverse();
    insert(4, 70); // 30 40 10 20 70(address=5)
    traverse();
}

void erase_test() {
    cout << "****** erase_test *****\n";
    erase(1); // 30 40 20 70
    traverse();
    erase(2); // 40 20 70
    traverse();
    erase(4); // 40 70
    traverse();
    erase(5); // 40
    traverse();
}

int main(void) {
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
    insert_test();
    erase_test();
}