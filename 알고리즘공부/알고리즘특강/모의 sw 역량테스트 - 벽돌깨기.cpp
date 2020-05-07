#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int answer, n, w, h;
int bc; // sa


void copy(int arr[16][13], int arr2[16][13]) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			arr2[i][j] = arr[i][j];
		}
	}
}

void rebuild(int arr2[16][13]) {

	stack<int> s;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if (arr2[j][i] != 0) {
				s.push(arr2[j][i]);
				arr2[j][i] = 0;
			}
		}
		int j = h - 1;
		while (!s.empty()) {
			arr2[j][i] = s.top();
			s.pop();
			j--;
		}
	}
}
int p = 0;
void solve(int b, int arr[16][13] ,int sa, int cc) {
	
	if (cc == n) {

		answer = max(answer, sa); 

		return;
	}
	

	int a = -1;
	for (int i = 0; i < h; i++) {
		if (arr[i][b] != 0) {
			a = i;
			break;
		}
	}


	int arr2[16][13];
	int cnt = 1;
	copy(arr, arr2);
	queue<pair<pair<int, int>, int>> q;

	if (a != -1) {

		q.push({ { a,b }, arr[a][b] });

		while (!q.empty()) {
			int na = q.front().first.first;
			int nb = q.front().first.second;
			int c = q.front().second;
			q.pop();
			arr2[na][nb] = 0;

			for (int i = 1; i < c; i++) { // 오른쪽
				if (na >= 0 && nb >= 0 && na < h && nb + i < w && arr2[na][nb + i] != 0) {
					q.push({ {na,nb + i}, arr2[na][nb + i] });
					arr2[na][nb + i] = 0;
					cnt++;
				}
			}

			for (int i = 1; i < c; i++) { // 왼쪽
				if (na >= 0 && nb - i >= 0 && na < h && nb < w && arr2[na][nb - i] != 0) {
					q.push({ { na,nb - i }, arr2[na][nb - i] });
					arr2[na][nb - i] = 0;
					cnt++;
				}
			}

			for (int i = 1; i < c; i++) { // 아래
				if (na >= 0 && nb >= 0 && na + i < h && nb < w && arr2[na + i][nb] != 0) {
					q.push({ { na + i, nb }, arr2[na + i][nb] });
					arr2[na + i][nb] = 0;
					cnt++;
				}
			}

			for (int i = 1; i < c; i++) { // 위
				if (na - i >= 0 && nb >= 0 && na < h && nb < w && arr2[na - i][nb] != 0) {
					q.push({ { na - i, nb }, arr2[na - i][nb] });
					arr2[na - i][nb] = 0;
					cnt++;
				}
			}

		}

		rebuild(arr2);

	}
	
	for (int i = 0; i < w; i++) {

		solve(i, arr2, sa + cnt,cc + 1);
	}
	
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	int arr[16][13];

	for (int t = 1; t <= tc; t++) {
		cin >> n >> w >> h;
		bc = 0;
		answer = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
				if (arr[i][j] != 0) bc++;
			}
		}
		for (int i = 0; i < w; i++) {
			solve(i, arr,0,0);
		}
		if (bc - answer < 0) answer = bc;
		cout << "#" << t << " " << bc - answer << endl;
	}

	

	return 0;
}