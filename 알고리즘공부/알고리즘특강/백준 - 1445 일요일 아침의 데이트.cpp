#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <map>
#include <queue>
using namespace std;
int n, m;
string arr[51];
int check[51][51];
int start[2];
int finish[2];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void solve() {
	priority_queue<pair<int,pair<int, int>>> q;
	q.push({ 0,{ start[0],start[1] } });
	check[start[0]][start[1]] = 0;

	while (!q.empty()) {
		int a = q.top().second.first;
		int b = q.top().second.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int na = a + dx[i];
			int nb = b + dy[i];
			if (na >= 0 && nb >= 0 && na < n && nb < m && check[na][nb] == -1) {
				int cnt = 0;
				if (arr[na][nb] == 'g') cnt = 3000;
				else if (arr[na][nb] == 's') cnt = 1;
				check[na][nb] = check[a][b] + cnt;
				q.push({ -check[na][nb],{na,nb} });
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	 }
	memset(check, -1, sizeof(check));


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'S') {
				start[0] = i;
				start[1] = j;
			}
			else if (arr[i][j] == 'F') {
				finish[0] = i;
				finish[1] = j;
			}
			else if (arr[i][j] == 'g') {
				for (int t = 0; t < 4; t++) {
					int na = i + dx[t];
					int nb = j + dy[t];
					if (na >= 0 && nb >= 0 && na < n && nb < m && arr[na][nb] == '.') arr[na][nb] = 's';

				}
			}
		}
	}
	solve();
	cout << check[finish[0]][finish[1]]/3000 << " " << check[finish[0]][finish[1]] % 3000 << endl;

	return 0;
}