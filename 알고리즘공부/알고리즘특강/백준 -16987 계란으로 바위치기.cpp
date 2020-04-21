#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;

int n;
int arr[10][2];
int check[10]; // 0은 내구도 // 1은 무게
int answer = -1;
void solve(int a) {
	if (a == n) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i][0] <= 0) cnt++;
		}
		answer = max(answer, cnt);
		return;
	}
	if (arr[a][0] <= 0) {
		solve(a + 1); // 깨져있을 때.
		return;
	}

	bool strike = false;
	for (int i = 0; i < n; i++) {
		if (i == a || arr[i][0] <= 0) continue;

			arr[a][0] -= arr[i][1];
			arr[i][0] -= arr[a][1];
			strike = true;
			solve(a + 1);
			arr[a][0] += arr[i][1];
			arr[i][0] += arr[a][1];

	}
	if (strike == false) {
		solve(n);
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	memset(check, 0, sizeof(check));
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	solve(0);
	cout << answer << endl;
	return 0;
}
