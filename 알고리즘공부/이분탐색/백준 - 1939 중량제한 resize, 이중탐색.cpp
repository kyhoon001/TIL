#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int n, m, n1, n2, n3, start, des;
int maxn = 0;
vector<vector<int>> v;
vector<vector<int>> price;
int check[100001];

bool bfs(int cnt) {
	queue<int> q;
	q.push(start);
	check[start] = 1;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		if (tmp == des) return true;

		for (int i = 0; i < v[tmp].size(); i++) {
			if (price[tmp][i] >= cnt && check[v[tmp][i]] == 0) {
				check[v[tmp][i]] = 1;
				q.push(v[tmp][i]);
			}
		}

	}


	return false;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	v.resize(n);
	price.resize(n);
	
	

	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2 >> n3;
		maxn = max(maxn, n3);
		v[n1-1].push_back(n2-1);
		price[n1 - 1].push_back(n3);
		v[n2 - 1].push_back(n1 - 1);
		price[n2 - 1].push_back(n3);
	}



	cin >> start >> des;
	start -= 1;
	des -= 1;


	int l = 0;
	int r = maxn;

	while (l <= r) {
		memset(check, 0, sizeof(check));
		int mid = (l + r) / 2;

		if (bfs(mid)) {
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	cout << r;

}