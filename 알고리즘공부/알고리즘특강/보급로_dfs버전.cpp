#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
//#include<stdio.h>
using namespace std;

int tc, answer, n;
int arr[101][101];
int arr2[101][101];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };




void solve(int x, int y, int total, int px, int py) { // 처음에 줄 때 0,0의 값을 total로 줘야함.

	int xx, yy;
	if (x == n - 1 && y == n - 1) {
		answer = min(total, answer);
		
		return;
	}
	if (total >= answer ) {
		return;
	}
	if (arr2[x][y] != -1 && arr2[x][y] <= total) {
		return;
	}
	else {
		
		arr2[x][y] = total;
	}

	for (int i = 0; i < 4; i++) {
		xx = x + dx[i];
		yy = y + dy[i];
		if (xx == px && yy == py) {
			continue;
		}
		if (xx >= 0 && yy >= 0 && xx < n && yy < n) {
			solve(xx, yy, total + arr[xx][yy],x,y);
		}
	}

	



}





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		memset(arr2, -1, sizeof(arr2));
		
		answer = 99999999;
		
		for (int i = 0; i < n; i++) {
			cin >> s;
			for (int j = 0; j < n; j++) {
				arr[i][j] =(s[j]-'0');
			}
		}

		solve(0, 0, arr[0][0],-1,-1);
		



		cout << '#' << t << ' ' << answer << endl;

	}
}