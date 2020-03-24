#include <iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include <functional>
#include<stack>
using namespace std;

int arr[101][101];
int n, m, k, a, b, a2, b2;
int check[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
//vector<int> v;
priority_queue<int> q;
int answer = 0;
int cnt = 0;
void solve(int a, int b) {

			cnt ++;
			check[a][b] = 1;
	for (int i = 0; i < 4; i++) {
		int na = a + dx[i];
		int nb = b + dy[i];

		if (na >= 0 && nb >= 0 && na < n && nb < m && check[na][nb] == 0 && arr[na][nb] == 0) {

			solve(na, nb);
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	memset(arr, 0, sizeof(arr));
	memset(check, 0, sizeof(arr));

	
	for (int t = 0; t < k; t++) {
		cin >> b >> a >> b2 >> a2;

		for (int i = (n - 1) - a; i > (n - 1) - a2; i--) {
			for (int j = b; j < b2; j++) {
				arr[i][j] = 1;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 1 && check[i][j] == 0) {
				solve(i, j);
				q.push(-cnt);
				answer += 1;
				cnt = 0;
			}
		}
	}
		cout << answer << endl;
		while (!q.empty()) {
			cout << -q.top() << " ";
			q.pop();
		}

	return 0;
}