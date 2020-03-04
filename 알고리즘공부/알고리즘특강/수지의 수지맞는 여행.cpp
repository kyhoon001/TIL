#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
using namespace std;
int n, r, c;

int arr[21][21];
int visit[21][21];
int answer = 0;
int check[27]; // 알파벳
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int cnt = 0;

void solve(int a, int b) {


	answer = max(cnt, answer);
	

	int na, nb;

	for (int i = 0; i < 4; i++) {
		na = a + dx[i];
		nb = b + dy[i];

		if (na >= 0 && nb >= 0 && na < r && nb < c) { // 범위 안에 있으면
			if (check[arr[na][nb]] == 1 || visit[na][nb] == 1) {//1이 이미 본 관광물일 경우임.
				continue;
			}
			else if (check[arr[na][nb]] == 0 && visit[na][nb] == 0) { // 안 봤을 경우
				cnt += 1; // 하나 봤다고 추가해주고
				check[arr[na][nb]] = 1; // 해당 관광물 봤다고 check 해주고
				visit[na][nb] = 1;
				//cout << "na : " << na << "        nb : " << nb << "   그리고 cnt : " << cnt << endl;
				solve(na, nb); // 해당 관광물에서 다시 탐색.
				
				cnt -= 1; // 추가했던거 빼주고
				check[arr[na][nb]] = 0; // 해당 관광물 안 봤다고 복구 해주고
				visit[na][nb] = 0;

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
		memset(arr, -1, sizeof(arr));
		memset(check, 0, sizeof(check));
		memset(visit, 0, sizeof(visit));
		cin >> r >> c;
		string s;
		answer = 1;
		cnt = 1;
		for (int i = 0; i < r; i++) {
			cin >> s;
			for (int j = 0; j < c; j++) {
				arr[i][j] = s[j] - 'A';
			}
		}
		check[arr[0][0]] = 1;
		visit[0][0] = 1;
		solve(0, 0);


		cout << "#" << tc << " " << answer << endl;
		

	}


	return 0;
}