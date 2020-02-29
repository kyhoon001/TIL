#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, k;
int arr[9][9];
int check[9][9];
bool possible;
//하나를 찾고 그 다음걸 찾자.
int di[4] = { 1, 0, -1, 0 };
int dj[4] = { 0, 1, 0,  -1};
int answer = 1;


void solve(int ti, int tj, int mino, int cnt) { //mino는 얼마나 깎을 건지 값을 줌.
//	cout << "( " << ti << ", " << tj << " )  값은 : " << arr[ti][tj] - mino << "               " << cnt << endl;
		if (cnt > answer)
			answer = cnt;

		for (int i = 0; i < 4; i++) {
			int tmpi = ti + di[i];
			int tmpj = tj + dj[i];
			if (tmpi >= 0 && tmpj >= 0 && tmpi < n && tmpj < n) { // 범위 안에 있으면 
				if (arr[tmpi][tmpj] >= arr[ti][tj] - mino && possible == true) { //자신보다 더 높고 깎을 수 있을 때.
					possible = false;
					for (int j = 1; j <= k; j++) {
						if (arr[ti][tj] - mino > arr[tmpi][tmpj] - j && check[tmpi][tmpj] == 0) { // 가야할 곳의 값이 자신의 값보다 작아지면 이동
							check[tmpi][tmpj] = 1;
							solve(tmpi, tmpj, j, cnt + 1);
							check[tmpi][tmpj] = 0;
						}
					}
					possible = true;
				}
				else if (arr[tmpi][tmpj] < arr[ti][tj] - mino && check[tmpi][tmpj] == 0) {
					check[tmpi][tmpj] = 1;
					solve(tmpi, tmpj, 0, cnt + 1);
					check[tmpi][tmpj] = 0;
				}

			}
		}





}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> k;
		memset(check, 0, sizeof(check));
		answer = 1;
		int top = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (top < arr[i][j])
					top = arr[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == top) {
					memset(check, 0, sizeof(check));
					possible = true;
					check[i][j] = 1;
					solve(i, j, 0, 1);
					//여기서 함수 실행.
				}
			}
		}





		cout << "#" << tc << " " << answer << endl;// << pq.top() << endl;
		

	}


	return 0;
}