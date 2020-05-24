#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
using namespace std;

#define MOD 15746
int n;
int arr[1000001];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] = arr[i] % MOD;
	}
	cout << arr[n]<< endl;


	return 0;
}
