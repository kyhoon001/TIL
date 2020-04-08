#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;

int n;
vector<int> arr;
int DP[40001];
int length;
void solve() {
	DP[1] = arr[1];
	length = 1;

	for (int i = 2; i <= n; i++) {
		if (DP[length] < arr[i]) {
			length++;
			DP[length] = arr[i];
			continue;
		}
		int idx = lower_bound(DP+1, DP + length+1, arr[i]) - DP;
		DP[idx] = arr[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	arr.resize(n+1);
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	solve();
	cout << length << endl;
	return 0;
}
