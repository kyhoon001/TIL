# s/w 문제해결 응용 7일차 - 행렬찾기



```c++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;

int n;
int arr[101][101];
int check[101][101];
int xx;
int yy;
int msize;

priority_queue<pair<int, pair<int, int>>> pq;


void calc(int a, int b) {
	for (int i = b; i < n; i++) {
		if (arr[a][i+1] == 0) {
			xx = i - b + 1;
			break;
		}
	}

	for (int i = a; i < n; i++) {
		if (arr[i + 1][b] == 0) {
			yy = i - a + 1;
			break;
		}
	}

	msize = xx * yy;

	for (int i = a; i < a + yy; i++) {
		for (int j = b; j < b + xx; j++) {
			check[i][j] = 1;
		}
	}
	pq.push({ -msize, {-yy, -xx} });
	/*
	cout << "push한다 " << yy << "  하고 " << xx << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << check[i][j] << " ";

		}
		cout << endl;
	}
	cout << endl << endl << endl << endl;
	*/
}









int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		memset(check, 0, sizeof(check));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] != 0 && check[i][j] == 0) {
					calc(i, j);
				}
			}
		}

		int xtmp;
		int ytmp;

		cout << "#" << tc << " " << pq.size() << " ";
		//for (int i = 0; i < sizeof(pq) -1; i++) {
		while(!pq.empty()) {
			xtmp = -pq.top().second.second;
			ytmp = -pq.top().second.first;

			//cout << pq.top().second.x << " " << pq.top().second.y << " ";
			cout << ytmp << " " << xtmp << " ";
			
			pq.pop();
		}
		cout << endl;

	}



	return 0;
}
```

