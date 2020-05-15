#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int answer, n, m, k;
int arr[14][21];
int arr2[14][21];
bool f = false;
bool pass() {
	bool check;
	for (int j = 0; j < m; j++) {
		check = false;
		int cnt = 1;
		int tmp = arr2[0][j];
		for (int i = 1; i < n; i++) {
			if (arr2[i][j] == tmp) {
				cnt++;
			}
			else {
				cnt = 1;
				tmp = arr2[i][j];
			}
			if (cnt == k) {
				check = true;
				break;
			}
		}
		if (check == false) return false;
	}
	return true;
}


void ch(int a, int b) {
	for (int i = 0; i < m; i++) {
		arr2[a][i] = b;
	}
}

void uch(int a) {
	for (int i = 0; i < m; i++) {
		arr2[a][i] = arr[a][i];
	}
}


bool solve(int a, int b, int cnt) { //cnt는 0부터 주자
	if (cnt >= b) {
		if (pass()) {
			return true;
		}
		return false;
	}


	for (int t = a; t < n; t++) {
		for (int i = 0; i < 2; i++) {

			ch(t, i);
			if (solve(t + 1, b, cnt + 1)) return true;
			uch(t);
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> m >> k; //k가 기준.

		answer = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				arr2[i][j] = arr[i][j];
			}
		}
		if (pass()) {
			cout << "#" << t << " " << 0 << endl;
			continue;
		}

		for (int i = 1; i < k; i++) {
			if (solve(0, i, 0)) {
				answer = i;
				break;
			}
		}
		if (answer == -1) answer = k;

		cout << "#" << t << " " << answer << endl;
	}


	return 0;
}