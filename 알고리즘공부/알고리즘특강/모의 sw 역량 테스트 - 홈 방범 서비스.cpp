#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

int n, m, answer;
int cost[21];
int arr[21][21];
int check[21][21];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };



void solve(int a, int b) {

	queue<pair<int, int>> q;
	q.push({ a, b });
	int tmp = 0;
	int c = 1;
	check[a][b] = 1;
	if (arr[a][b] == 1) tmp += 1;
	while (!q.empty()) {
		if (c > n + 1) break;
		if (cost[c] <= tmp * m) {
			answer = max(answer, tmp);
		}
		int s = q.size();
		for (int i = 0; i < s; i++) {
			int na = q.front().first;
			int nb = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int x = na + dx[i];
				int y = nb + dy[i];
				if (x >= 0 && y >= 0 && x < n && y < n && check[x][y] == 0) {
					check[x][y] = 1;
					q.push({ x,y });
					if (arr[x][y] == 1) {
						tmp++;
					}
				}
			}
		}
		c++;
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	///////////////////////
	cost[1] = 1;
	for (int i = 2; i <= 21; i++) {
		int tmp = 1;
		for (int j = 1; j < i; j++) {
			cost[i] += tmp;
			tmp += 2;
		}
		cost[i] = cost[i] * 2 + tmp;
	}
	//////////////////////
	for (int t = 1; t <= tc; t++) {
		cin >> n >> m;
		answer = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					memset(check, 0, sizeof(check));
					solve(i, j);
				}
			}

		cout << "#" << t << " " << answer << endl;
	}

	

	return 0;
}