#include <iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;
int n, m;
int arr[101][101];
queue<pair<int, int>> q;
queue<pair<int, int>> q2;
int check[101][101];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void solve(int a, int b) {
	check[a][b] = 1;
	int na, nb;

	for (int i = 0; i < 4; i++) {
		na = a + dx[i];
		nb = b + dy[i];

		if (na >= 0 && nb >= 0 && na < n && nb < m) {
			if (arr[na][nb] == 1 && check[na][nb] == 0) {
				q.push({ na,nb });
				check[na][nb] = 1;
			}
			else if (arr[na][nb] == 0 && check[na][nb] == 0) {
				check[na][nb] = 1;
				solve(na, nb);
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
	int cnt = 0;
	int tmp = 0;
	memset(check, 0, sizeof(check));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> n1;
			arr[i][j] = n1;
		}
	}
	while (1) {

		bool change = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0 && check[i][j] == 0) {
					solve(i, j);
					change = true;
					break;
				}
			}
			if (change == true) break;
		}
		
		tmp = q.size();
		while (!q.empty()) {
			int i = q.front().first;
			int j = q.front().second;
			arr[i][j] = 0;
			check[i][j] = 1;
			q.pop();
		}
		


		cnt += 1;
		change = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1) {
					change = true;
				}
			}
		}
		if (change == false) break;
		memset(check, 0, sizeof(check));

	}
	cout << cnt << endl << tmp << endl;

	return 0;

}