#include <iostream>
#include <bits/stdc++.h>
#include <time.h>

using namespace std;
int n, x;
int arr[10001];

int main()
{
    cin.tie(0);
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] < x) {
            cout << arr[i] << " ";
        }
    }

    return 0;
}

// 시간복잡도 : O(N)
// 걸린시간 : 1432ms
// 메모리 : 8byte + 40004byte = 약 40000 byte 사용