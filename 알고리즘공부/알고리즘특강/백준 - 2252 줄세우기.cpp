#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <map>
using namespace std;
int n, m;

int arr[33000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	vector<vector<int>> v(33000);
	
	queue<int> q, answer;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		arr[b] += 1;
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) q.push(i);
	}
	
	for (int i = 1; i <= n; i++) {
		if (q.empty()) return 0;

		int t = q.front();
		q.pop();
		answer.push(t);

		for (int j = 0; j < v[t].size(); j++) {
			arr[v[t][j]] -= 1;
			if (arr[v[t][j]] == 0) q.push(v[t][j]);
		}
		
	}
	while(!answer.empty()) {
		cout << answer.front() << " ";
		answer.pop();
	}

	return 0;
}