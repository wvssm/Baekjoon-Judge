// 시간초과 나는 코드
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> save;
int n, m;
int arr[10];
int input[10];
int isused[10];
int arrayused[40400][10];

void func(int cur) {
	if (cur == m) {
		vector<int> nums;
		for (int i = 0; i < m; i++) {
			nums.push_back(input[arr[i]]);			
			//cout << input[arr[i]] << ' ';
			
		}
		if (save.size() > 0) {
			for (int i = 0; i < save.size(); i++) {
				if (equal(save[i].begin(),save[i].end(),nums.begin(),nums.end())) return;
			}
		}
		for (int i = 0; i < nums.size(); i++) cout << nums[i] << ' ';
		save.push_back(nums);
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!isused[i]) {
			arr[cur] = i; // arr의 cur번째 자리에 인덱스 넣기
			isused[i] = 1;
			func(cur + 1);
			isused[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input, input + n);
	func(0);
}