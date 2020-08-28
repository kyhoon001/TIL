//처음에는 비트마스킹으로 접근해서 틀렸음.
// 다른 사람들 해답 많이 참고했는데 이해하는데 시간이 좀 걸렸음.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <map>
using namespace std;
int n, m;

int a[101];
int b[101];
int dp[10001];
int answer = 987654321;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		tmp += b[i]; // 최대 비용.
	}
//	cout << "debug" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = tmp; j >= b[i]; j--) { // 최대비용부터 내려오면서
			// 최대비용에서 할 수 있는 것 = 현재 최대, 현재 최대- i의 코스트를 뺀 것에서 가장 큰 것
			dp[j] = max(dp[j], dp[j - b[i]] + a[i]);
			//j비용 = max(현재 j비용 값, i가 포함되었을 때의 비용값)
			
		}
	}
	int i = 0;
	for (i = 0; i < tmp, dp[i] < m; i++);
	cout << i << endl;

	return 0;
}