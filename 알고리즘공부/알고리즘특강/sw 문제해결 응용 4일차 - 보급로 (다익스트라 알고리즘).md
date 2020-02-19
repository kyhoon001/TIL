# s/w 문제해결 응용 4일차 - 보급로 (다익스트라 알고리즘)

- 참고한 코드 : 다익스트라 알고리즘
- priority_queue 의 경우 정렬되서 들어감. 기본값은 less<int>로 설정되어서 top이 최대값.
- greater<int>를 주면 top가 최소값으로 변함.

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int map[111][111];
int d[111][111];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int n;

bool inner(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < n);
}

int dijk() {
	memset(d, -1, sizeof(d));
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,{0,0} });

	while (!pq.empty()) {


		int cost = -pq.top().first;
		//int cost = pq.top().first;

		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		if (d[x][y] == -1) d[x][y] = cost;
		cout << endl << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << d[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl << endl;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!inner(nx, ny)) continue;
			//int ncost = -cost - map[nx][ny];
			int ncost = 0;
			ncost -= cost + map[nx][ny];


			if (d[nx][ny] == -1) pq.push({ ncost,{nx,ny} });
		}
	}
	return d[n - 1][n - 1];
}


int main() {
//	freopen("input.txt","r",stdin);
	int tc; scanf(" %d", &tc); int c = 1;
	while (tc--) {
		scanf(" %d", &n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf(" %1d", &map[i][j]);
			}
		}
		printf("#%d %d\n", c++, dijk());
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << d[i][j] << " ";
			}
			cout << endl;
		}
	}

}
```



- 내가 따라한 알고리즘

```c++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int arr[101][101];
int n;
int d[101][101];
int q;

int la[4] = { 1, 0, -1, 0 };
int lb[4] = { 0, 1, 0, -1 };

void solve() {
	// cost가 작은것부터 차례대로 탐색하니까 최솟값을 찾을 수 있음.
	priority_queue<pair<int, pair<int, int>>> pq;
	//이게 greater<int>를 주는게 안 되서, cost값을 음수로 큐에 넣은 뒤에, 쓸때는 다시 양수로
	//변환해서 써주어야 할듯
	pq.push({ 0,{0, 0} });
	while (!pq.empty()) {
		int cost = -pq.top().first; // -값인 이유는 출력 형태를 역순으로 하기 위해서임.
		//1 < 2 이지만 -1 > -2 니까 오름차순 --> 내림차순으로 변환시키는 것과 같이 동작함.
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		pq.pop();

		if (d[a][b] == -1) { // -1이면 아직 탐색이 안 되었다는 의미임. 
			d[a][b] = cost;	// 아직 탐색이 안 되었으니까 cost값을 넣어줌.
		}


		for (int i = 0; i < 4; i++) {
			int na = a + la[i];
			int nb = b + lb[i];

			if (na >= 0 && nb >= 0 && na < n && nb < n) { //만약 범위안에 있으면
				if (d[na][nb] != -1) { // 이미 탐색되었으면 넘어간다.
					continue;
				}
				int tmp = 0;
				tmp -= cost + arr[na][nb];
				pq.push({ tmp,{na,nb} });
			}

		}



	}

	cout << "#" << q << " " << d[n - 1][n - 1] << endl;
}


int main() {
//		freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	string s;
	
	for (q = 1; q <= tc; q++) {
		cin >> n;

	

		for (int i = 0; i < n; i++) {
			cin >> s;
			for (int j = 0; j < n; j++) {
				arr[i][j] = (s[j] - '0');
				d[i][j] = -1;
			}
		}


		solve();
		//cout << "#" << q << " " << answer << endl;
	
	}
	return 0;
}
```

