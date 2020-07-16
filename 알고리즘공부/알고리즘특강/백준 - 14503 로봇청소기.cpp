#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
using namespace std;
int n, m;
int arr[51][51];
int answer = 0;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

//d = 위 왼 아래 우 이렇게 하자.

void solve(int r, int c, int d)
{
	if (arr[r][c] == 0) {
		arr[r][c] = 2;
		answer++;
	}
	int a = r;
	int b = c;
	int t = d;

	int block = 0; // 벽 체크하자

	for (int i = 0; i < 4; i++) {
		// 왼쪽으로 한 번씩 돌아줌.
		t += 1;
		// 4일경우 다시 0으로 idx 잡아줌.
		if (t == 4) t = 0;

		int na = a + dx[t];
		int nb = b + dy[t];

		if (na >= 0 && nb >= 0 && na < n && nb < m) {
			if (arr[na][nb] == 0) {
				//answer++;
				solve(na, nb, t);
				return;
			}
			if (arr[na][nb] == 1) { // 벽일 경우.
				block++;
			}
		}
		
	}
	if (block == 4) { // 4방향이 벽일 경우
		return;
	}

	int na, nb;

	if (d == 0) {
		na = a + dx[2];
		nb = b + dy[2];
		if (arr[na][nb] != 1) {
			solve(na, nb,d);
		}
	}
	else if (d == 1) {
		na = a + dx[3];
		nb = b + dy[3];
		if (arr[na][nb] != 1) {
			solve(na, nb, d);
		}
	}
	else if (d == 2) {
		na = a + dx[0];
		nb = b + dy[0];
		if (arr[na][nb] != 1) {
			solve(na, nb, d);
		}
	}
	else if (d == 3) {
		na = a + dx[1];
		nb = b + dy[1];
		if (arr[na][nb] != 1) {
			solve(na, nb, d);
		}
	}

}





int main()
{
	cin >> n >> m;
	int r, c, d; // d = 북 동 남 서.  헷갈리니까 위 왼쪽 아래 오른쪽으로 할거임
	cin >> r >> c >> d; 
	
	// 왼쪽으로 돌기 위해서 넣어줬음.
	if (d == 1) d = 3;
	else if (d == 3) d = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	solve(r, c, d);
	cout << answer << endl;

	return 0;
}