#include <iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include <functional>
using namespace std;

int tc;
int n,c,r;
int arr[101][101];
int check[101][101];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int g = 0;
priority_queue<pair<int, pair<int, int>>> q;
vector<pair<int, int>> v;

void solve(int a, int b) {

	if (arr[a][b] == 0 || check[a][b] != 0) {
		return;
	}

	check[a][b] = g;
	for (int i = 0; i < 4; i++) {
		int na = a + dx[i];
		int nb = b + dy[i];

		if (na >= 0 && nb >= 0 && na < n && nb < n) {
			solve(na, nb);
		}

	}
	
}

void find_c(int a, int b) {
	c++;
	if (a + 1 < n) {
		if (check[a + 1][b] == check[a][b]) {
			find_c(a + 1, b);
		}
	}
	return;
}

void find_r(int a, int b) {
	r++;
	if (b + 1 < n) {
		if (check[a][b + 1] == check[a][b]) {
			find_r(a, b + 1);
		}
	}
	return;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		memset(arr, 0, sizeof(arr));
		memset(check, 0, sizeof(arr));
		g = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == 0 && arr[i][j] != 0) {
					g += 1;
					solve(i, j);
					v.push_back({ i, j });
				}
			}
		}

		for (int i = 0; i < g; i++) {
			c = 0;
			r = 0;
			find_c(v[0].first, v[0].second);
			find_r(v[0].first, v[0].second);
			v.erase(v.begin());
//			cout << c << "   " << r << endl;
			q.push({ -(c * r), {-c,-r} });
		}



		cout << "#" << t << " " << g << " ";
		while (!q.empty()) {
			cout << -q.top().second.first << " " << -q.top().second.second << " ";
			q.pop();
		}
		cout << endl;
	}
	return 0;
}