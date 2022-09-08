// Authored by : OceanShape
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/a3d03c0124b544759d306668e55bbf4b
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while (N--) {
        int a[26] = {};
        string s1, s2;
        cin >> s1 >> s2;

        for (auto c : s1) a[c - 'a']++;
        for (auto c : s2) a[c - 'a']--;

        bool isPossible = true;
        for (int i : a) {
            if (i != 0) isPossible = false;
        }

        if (isPossible) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}

// 첫번째 문자열의 알파벳 표시 +1
// 두번째 문자열의 알파벳 표시 -1
// 배열 전체의 값이 0이면 두 문자열은 Strfry 관계

// 시간복잡도 : O(3*N)
// 내 방법보다 메모리를 아낄 수 있음