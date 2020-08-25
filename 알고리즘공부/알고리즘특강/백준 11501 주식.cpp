//단순하게 완전탐색으로 풀이했음. 완탐으로 먼저 문제를 해결하고 그 이후에 성능을 고려하자
//자료형 잘 보자 자료형 틀려서 시간 잡아먹혔음. int long long

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <map>
using namespace std;
int n, m, t;
int arr[10000000] = { 0 };
int dp[10000000] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;
	
	for (int tc = 0; tc < t; tc++) {
		cin >> n;
		long long answer = 0;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int n1 = 0, n2 = 0, n3 = 0;
		while (n1 != n) {

			for (int i = n1; i < n; i++) {
				n2 = max(n2, arr[i]);
				if (n2 == arr[i]) n3 = i;

			}

			for (int i = n1; i < n3; i++) {
				answer += n2 - arr[i];
			}
			if(n1 < n3) n1 = n3 + 1;
			else n1 += 1;
			n2 = 0;
		}
		cout << answer << endl;
	}
	return 0;
}