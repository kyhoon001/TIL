#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
using namespace std;
int n, m;
int arr[21][21];
int check[21][21];
int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,1,-1 };
int answer = 0;
int tmp = 0;
vector<pair<int, int>> v;
bool f = false; // search 코드를 재활용하기 위함.
//탐색 : 
void search(int a, int b) { // 2를 죽여야함
	tmp = 1;
	queue<pair<int, int>> q;
	q.push({ a,b });
	check[a][b] = 1;
	int cnt = 0;
	while (!q.empty()) {
		int aa = q.front().first;
		int bb = q.front().second;
		q.pop();		for (int i = 0; i < 4; i++) {
			int na = aa + dx[i];
			int nb = bb + dy[i];
			if (na >= 0 && nb >= 0 && na < n && nb < m && check[na][nb] == 0) {
				if (arr[na][nb] == 0) {
					cnt++;
					if(f == false) //재활용
						v.push_back({ na,nb });
				}
				else if (arr[na][nb] == 2) {
					q.push({ na,nb });
					tmp++;
				}
				
				check[na][nb] = 1;
				if (arr[na][nb] == 0 && f == true) check[na][nb] = 0; //재활용
			}
		}
		if (cnt != 0) {
			tmp = 0;
		}
	}

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//1. 흑돌이 있는데서 탐색하면서 만나는 0을 착수 가능한 지점으로 배열에 넣어줌..
	//2. 2중 포문으로 배열에서 착수 가능한 것을 뽑음. 그 다음에 완탐하면서 몇 개가 최대인지를 받음.
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 2 && check[i][j] == 0) search(i, j);
		}
	}
	f = true;
	////////////////////////////////////여기까지 해서 1번 클리어.

	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) { // 조합을 뽑기 위함.

			tmp = 0;
			int ttmp = 0;
			memset(check, 0, sizeof(check));
			arr[v[i].first][v[i].second] = 1;
			arr[v[j].first][v[j].second] = 1;

			for (int a = 0; a < n; a++) { // 돌면서 몇개 죽일 수 있는지 계산
				for (int b = 0; b < m; b++) {
					if (arr[a][b] == 2 && check[a][b] == 0) {
						search(a, b);
						ttmp += tmp;
					}
				}
			}
			answer = max(answer, ttmp);
			arr[v[i].first][v[i].second] = 0;
			arr[v[j].first][v[j].second] = 0;

		}
	}
	cout << answer << endl;
	return 0;
}
