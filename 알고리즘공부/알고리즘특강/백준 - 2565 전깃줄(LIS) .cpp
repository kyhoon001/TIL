#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;

int n;
int DP[110];
int length;
pair<int, int> arr[110];

void solve() {
	DP[0] = arr[0].second;
	length = 0;
	int idx = 0;
	for (int i = 1; i < n; i++) {
		
		if (DP[idx] < arr[i].second) {
			idx++;
			DP[idx] = arr[i].second;
			//멀쩡하게 감.
//			length++;
		}
		else {
			int idx2 = lower_bound(DP, DP + idx, arr[i].second) - DP;
			DP[idx2] = arr[i].second;
			length++;
			//꼬여서 다시 재정렬함. 제거해야 하는 개수를 찾는 문제니까 여기서 length를 셈
		}
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	memset(DP, 0, sizeof(DP));
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + n);
	solve();
	cout << length << endl;


	return 0;
}
