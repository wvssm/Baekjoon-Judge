// Authored by : std-freejia
// Co-authored by : BaaaaaaaaaaarkingDog, rhsnfl1122
// http://boj.kr/cbef82389d1048db80c9652d18b71304
#include <bits/stdc++.h>
using namespace std;

stack<char> s;
string str;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    int sum = 0; // �����ؼ� ������ ��
    int num = 1; // ������ ��

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            num *= 2; // �Ұ�ȣ�� ������ ������ �� 2�� ����
            s.push(str[i]);
        }
        else if (str[i] == '[') {
            num *= 3; // ���ȣ�� ������ ������ �� 3�� ����
            s.push(str[i]);
        }
        else if (str[i] == ')') {
            if (s.empty() || s.top() != '(') {
                cout << 0;
                return 0;
            }
            if (str[i - 1] == '(') sum += num; // ���� ��ȣ�� ���� ��ȣ���ٸ� sum�� �� �߰�
            s.pop();
            num /= 2; // �Ұ�ȣ ���� ��������� 2�� ����      
        }
        else { // str[i] == ']'
            if (s.empty() || s.top() != '[') {
                cout << 0;
                return 0;
            }
            if (str[i - 1] == '[') sum += num; // ���� ��ȣ�� ���� ��ȣ���ٸ� sum�� �� �߰�
            s.pop();
            num /= 3; // ���ȣ ���� ��������� 3�� ����
        }
    }
    if (s.empty()) cout << sum;
    else cout << 0;
}

/*
boj 10799 �� ����� ������ ���̵��� ����ϰ� �پ��ִ� () Ȥ�� []�� ������
sum�� ������ ������. () Ȥ�� []�� �� ���ΰ��� ��ø�� �Ұ�ȣ/���ȣ�� ������
��� �����ϰ� �̴� ���� num�� ������ ��.
*/