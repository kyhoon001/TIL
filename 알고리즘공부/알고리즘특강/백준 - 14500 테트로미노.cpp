#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<time.h>
using namespace std;
int answer, n, m, k;
int arr[501][501];
int check[501][501];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };


//처음에는 도형을 하나 하나 다 돌리게 만들려고 짱구를 많이 굴렸음.
//근데 생각해보니까 4방향으로 4블록씩 DFS하면 돌린 모든 도형을 찾을 수 있었음.
//여러 방면으로 생각을 해봐야 한다는 것을 배움.


void solve(int a, int b,int cnt, int tmp) {
	if (cnt == 3) {
		answer = max(tmp, answer);
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int na = a + dx[i];
		int nb = b + dy[i];

		if (na >= 0 && nb >= 0 && na < n&& nb < m && check[na][nb] == 0) {
			check[na][nb] = 1;
			solve(na, nb, cnt + 1, tmp + arr[na][nb]);
			check[na][nb] = 0;
		}
	}
}

void solve2(int a, int b) {
	int tmp;
	if (a >= 0 && a + 2 < n) { // l 이 모양으로 아래로 뻗는 것.
		tmp = arr[a][b] + arr[a + 1][b] + arr[a + 2][b];
		if (b - 1 >= 0) {
			tmp += arr[a + 1][b - 1]; // ㅓ모양
			answer = max(answer, tmp);
			tmp -= arr[a + 1][b - 1];
		}
		if (b + 1 < m) { // ㅏ모양
			tmp += arr[a + 1][b + 1]; // ㅓ모양
			answer = max(answer, tmp);
			tmp -= arr[a + 1][b + 1];
		}
	}
	if (b >= 0 && b + 2 < m) { // ㅡ 이 모양으로 아래로 뻗는 것.
		tmp = arr[a][b] + arr[a][b + 1] + arr[a][b + 2];
		if (a - 1 >= 0) { // ㅗ모양
			tmp += arr[a - 1][b + 1];
			answer = max(answer, tmp);
			tmp -= arr[a - 1][b + 1];
		}
		if (a +1 < n) { // ㅗ모양
			tmp += arr[a + 1][b + 1];
			answer = max(answer, tmp);
			tmp -= arr[a + 1][b + 1];
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check[i][j] = 1;
			solve(i, j, 0, arr[i][j]);
			check[i][j] = 0;
			solve2(i, j);
		}
	}
	cout << answer << endl;
	return 0;
}
