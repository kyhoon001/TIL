# s/w 문제해결 기본 10일차 -Contact

```c++
#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int arr[101];
queue<int> q;
int cost;

void bfs(vector<int> v[], int start) {
	cost = arr[start] + 1;
	for (int i = 0; i < v[start].size(); i++) {
		if (arr[v[start][i]] == 0) { // 탐색이 안 되었다면
			arr[v[start][i]] = cost;
			q.push(v[start][i]);
		}
	}

}

void solve(vector<int> v[], int start) {
	while(!q.empty()) {
		int tmp = q.front();
		q.pop();
		cost = arr[tmp];
		bfs(v, tmp);
	}
	

}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	for (int t = 1; t <= 10; t++) {
		cin >> n >> m;
		vector<int> v[101];

		for (int i = 0; i < 101; i++) {
			arr[i] = 0;
		}

		for (int i = 0; i < n / 2; i++) {
			int num1;
			int num2;
			cin >> num1 >> num2;
			v[num1].push_back(num2);
		}
		arr[m] = 1;
		q.push(m);
		solve(v, m);

	int answer = 0;
	for (int i = 0; i < 101; i++) {
		if (arr[answer] <= arr[i]) {
			answer = i;
		}
	}
	cout <<"#" << t << " " << answer << endl;
	}


	return 0;
}
```

