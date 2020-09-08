#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <map>
#include <queue>
using namespace std;

int n, m,t;
int arr[51][51];
int arr2[51][3];
vector<int> v;
//x = 몇 번째 회전시킬건지. x의 배수를 회전시킴
//d = 0이면 시계 1이면 반시계
//k = 몇 바퀴 돌릴지.


void solve(int a, int b, int c) // a는 몇의 배수인지 b 는 시계인지 반시계인지 c는 몇바퀴
{
	c %= m;
	int idx = a;
	bool check = false;
	vector<pair<int, int>> del;
	while (idx <= n)
	{
		queue<int> q;
		if(b == 0) {
			//cout << "시계" << endl;
			for (int i = m- c; i < m; i++) {
				q.push(arr[idx][i]);
			}
			for (int i = 0; i < m - c; i++) {
				q.push(arr[idx][i]);
			}
		}

		else {
			//cout << "반시계" << endl;
			for (int i = c; i < m; i++) {
				q.push(arr[idx][i]);
			}
			for (int i = 0; i < c; i++) {
				q.push(arr[idx][i]);
			}
		}
		for (int i = 0; i < m; i++) {
			arr[idx][i] = q.front();
			q.pop();
		}
		idx += a;
	}
	// 돌리는거 끝////////////

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) continue; // 일치하면 0으로 없애줄거임 // 0이면 없다는 뜻
			idx = arr[i][j];
			//같은 원반에서 인접한 경우 처리
			if (j == 0) {
				if (arr[i][m - 1] == idx) {
					del.push_back({ i,j });
					del.push_back({ i,m-1 });
					check = true;
				}
				if (arr[i][j + 1] == idx) {
					del.push_back({ i,j });
					del.push_back({ i,j + 1 });
					check = true;
				}
			}
			else if (j != m - 1) {
				if (arr[i][j-1] == idx) {
					del.push_back({ i,j-1 });
					del.push_back({ i,j});
					check = true;
				}
				if (arr[i][j + 1] == idx) {
					del.push_back({ i,j });
					del.push_back({ i,j + 1 });
					check = true;
				}
			}
			//같은 원반 경우 끝
			//다른 원반의 경우
			if (i == 1) {
				if (arr[i+1][j] == idx) {
					del.push_back({ i,j });
					del.push_back({ i+1,j });
					check = true;
				}
			}
			else if (i != n) {
				if (arr[i-1][j] == idx) {
					del.push_back({ i-1,j });
					del.push_back({ i,j});
					check = true;
				}
				if (arr[i+1][j] == idx) {
					del.push_back({ i,j });
					del.push_back({ i+1,j});
					check = true;
				}
			}
		}
	}

	del.erase(unique(del.begin(), del.end()), del.end()); // 중복 제거
	for (int i = 0; i < del.size(); i++) {
		arr[del[i].first][del[i].second] = 0;
	}

	double sum = 0, cnt = 0;
	if (check == false) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0) continue;
				sum += arr[i][j];
				cnt++;
			}
		}
		sum /= cnt;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0) continue;
				if (arr[i][j] > sum) arr[i][j] -= 1;
				else if (arr[i][j] < sum) arr[i][j] += 1;
			}
		}
	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int answer = 0;
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr2[i][j];
		}
	}
	
	for (int i = 0; i < t; i++) {
		solve(arr2[i][0], arr2[i][1], arr2[i][2]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			answer += arr[i][j];
		}
	}
	cout << answer << endl;

	return 0;
}