#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int n, m;
int arr[9][9];
int check[9][9];
vector<pair<int, int>> v;
vector<pair<int, int>> z;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int cnt = 0;
int answer = 100;

void bfs(int a, int b) {
	if (check[a][b] == 1) return;
	queue<pair<int, int>> q;
	q.push({ a,b });
	check[a][b] = 1;
	cnt += 1;
	while (!q.empty()) {
		a = q.front().first;
		b = q.front().second;
		q.pop();

		if (cnt >= answer) {
			return;
		}

		for (int i = 0; i < 4; i++) {
			int na = a + dx[i];
			int nb = b + dy[i];

			if (na >= 0 && nb >= 0 && na < n && nb < m && check[na][nb] == 0 && arr[na][nb] != 1) {
				check[na][nb] = 1;
				q.push({ na,nb });
				cnt++;

			}

		}
	}
}

void solve() {
	for (int i = 0; i < z.size()-2; i++) {
		for (int j = i + 1; j < z.size()-1; j++) {
			for (int t = j + 1; t < z.size(); t++) {
				cnt = 0;
				memset(check, 0, sizeof(check));
				arr[z[i].first][z[i].second] = 1;
				arr[z[j].first][z[j].second] = 1;
				arr[z[t].first][z[t].second] = 1;
				for (int k = 0; k < v.size(); k++) {
					bfs(v[k].first, v[k].second);
				}
				answer = min(cnt, answer);
				
				arr[z[i].first][z[i].second] = 0;
				arr[z[j].first][z[j].second] = 0;
				arr[z[t].first][z[t].second] = 0;

			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int n1;
	int num1 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> n1;
			arr[i][j] = n1;
			if (n1 == 0) {
				z.push_back({ i,j });
			}
			else if (n1 == 2) {
				v.push_back({ i,j });
			}
			else if (n1 == 1) {
				num1++;
			}
		}
	}


	solve();
	cout << n * m - answer - num1 - 3 << endl;

	return 0;
}