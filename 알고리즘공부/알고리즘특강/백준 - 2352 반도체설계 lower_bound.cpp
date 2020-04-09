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
			//현재보다 더 큰 숫자가 나올경우 이건 증가하는 수열이라는 의미
			// length는 증가하는 개수겸, DP의 index를 의미함
			// DP[length]를 하면 증가 수열의 가장 큰 수가 나옴
		}
		int idx = lower_bound(DP+1, DP + length+1, arr[i]) - DP;
		DP[idx] = arr[i];
		// 증가하는 와중에 더 작은 숫자가 나올 경우
		// 해당 해당 숫자보다 큰 숫자가 처음 등장하는 위치의 숫자를 현재 숫자로 바꿔줌
		// 즉 DP에 저장되어 있는 숫자는 쓸 수 없음
		// 예제의 경우 2, 3, 5 가 답이지만
		// 해당 코드를 돌렸을 경우 1, 3, 5임. 즉 배열의 마지막 숫자만 의미가 있음.
		
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
