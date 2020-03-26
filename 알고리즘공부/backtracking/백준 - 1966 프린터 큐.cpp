#include <iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
using namespace std;

queue<pair<int,int>> q;
priority_queue<int> pq;
int t,n,m, n1;

void solve() {
	int cnt = 1;
	while (1) {
			if (q.front().first == m && q.front().second == pq.top()) {

				cout << cnt << endl;
				return;
			}

			else {
				int f, s;
				f = q.front().first;
				s = q.front().second;

				if (s == pq.top()) {
					pq.pop();
					q.pop();
					cnt += 1;
				}
				else if (s != pq.top()) {
					q.pop();
					q.push({ f,s });
				}
			}

		}
	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int tc = 0; tc < t; tc++) {
	
		cin >> n >> m;
		while (!q.empty()) q.pop();
		while (!pq.empty()) pq.pop();
		for (int i = 0; i <  n; i++) {
		
			cin >> n1;
			q.push({ i,n1 });
			pq.push(n1);
		}

		solve();

	}
	


	return 0;
}