#include <iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include <functional>
#include<stack>
using namespace std;

int tc;
int n, c, r,len;
int arr[101][101];
int check[101][101];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int g = 0;
vector<pair<int, int>> q;
vector<pair<int, int>> v;
stack<int> s;
vector<pair<int, int>> set;

bool cansave = false;
int dp[30][30];

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
void mkset(vector<int> check2, int a,int cnt) {
	for (int i = 0; i < q.size(); i++) {
		if (a == i) continue;
		if (q[a].second == q[i].first && check2[i] == 0) {
			check2[i] = 1;
			mkset(check2, i, cnt + 1);
			check2[i] = 0;
		}
	}
	len = max(len, cnt);
	if (len == cnt) {
		while (!s.empty()) {
			s.pop();
		}
		cansave = true;
	}
	if (cansave == true) {
		s.push(a);
	}
}

int calc(int p1, int p2) {

	if (dp[p1][p2] != -1)return dp[p1][p2];
	else {

		int result_min = 999999;

		for (int i = p1; i < p2; i++) {
			result_min = min(result_min, calc(p1, i) + calc(i + 1, p2) + (set[p1].first * set[i].second * set[p2].second));
		}

		return dp[p1][p2] = result_min;
	}
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
		q.clear();
		v.clear();
		set.clear();
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
		vector<int> check2;
		for (int i = 0; i < g; i++) {
			c = 0;
			r = 0;
			find_c(v[0].first, v[0].second);
			find_r(v[0].first, v[0].second);
			v.erase(v.begin());
			//			cout << c << "   " << r << endl;
			q.push_back({c,r});
			check2.push_back(0);
		}


		len = 0;
		for (int i = 0; i < q.size(); i++) {
			cansave = false;
			mkset(check2, i, 1);
		}
		set.clear();


		while (!s.empty()) {
			set.push_back({ q[s.top()].first,q[s.top()].second });
			s.pop();
		}
		
		

		for (int i = 0; i < set.size(); i++) {
			for (int j = 0; j < set.size(); j++) {
				if (i == j)dp[i][j] = 0;
				else dp[i][j] = -1;
			}
		}

		calc(0, set.size() - 1);

		cout << "#" << t << " " << dp[0][set.size() - 1] << endl;
	}
	return 0;
}