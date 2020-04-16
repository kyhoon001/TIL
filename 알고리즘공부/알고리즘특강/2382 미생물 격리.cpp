#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include <queue>
using namespace std;
int n, m, k;
pair<int, int> arr[101][101];
//vector<pair<int, int>> bug;
priority_queue<pair<pair<int, int>, pair<int, int>>> q;
int answer = 0;

void up(int a, int b) {
	if (a - 1 == 0) { // 끝일 경우.
		q.push({ {a - 1,b},{arr[a][b].first/2,2} });
	}
	else 	q.push({ {a - 1,b},{arr[a][b].first,arr[a][b].second} });
	arr[a][b].second = 0;
	arr[a][b].first = 0;
	
}


void down(int a, int b) {
	if (a + 1 == n-1) { // 끝일 경우.
		q.push({ {a + 1,b},{arr[a][b].first / 2,1} });
	}
	else	q.push({ {a + 1,b},{arr[a][b].first,arr[a][b].second} });
	arr[a][b].second = 0;
	arr[a][b].first = 0;

}

void left(int a, int b) {
	if (b - 1 == 0) { // 끝일 경우.
		q.push({ {a,b - 1},{arr[a][b].first/2,4} });
	}
	else 	q.push({ {a,b - 1},{arr[a][b].first,arr[a][b].second} });
	arr[a][b].second = 0;
	arr[a][b].first = 0;

}

void right(int a, int b) {
	if (b + 1 == n-1) { // 끝일 경우.
		q.push({ {a,b + 1},{arr[a][b].first / 2,3} });
	}
	else 	q.push({ {a,b + 1},{arr[a][b].first,arr[a][b].second} });
	arr[a][b].second = 0;
	arr[a][b].first = 0;
}

void calc() {
	if (q.empty()) return;
//	answer = 0;
	int a, b, c, d;
	a = q.top().first.first;
	b = q.top().first.second;
	arr[a][b].first = q.top().second.first;
	arr[a][b].second = q.top().second.second;
//	answer += arr[a][b].first;
//	cout << arr[a][b].first << endl << arr[a][b].second << endl;
	q.pop();
	while (!q.empty()) {
		if (a == q.top().first.first && b == q.top().first.second) { // 곂친다면
			arr[a][b].first += q.top().second.first;
//			answer += q.top().second.first;
			q.pop();
		}
		else {
			a = q.top().first.first;
			b = q.top().first.second;
			arr[a][b].first = q.top().second.first;
			arr[a][b].second = q.top().second.second;
//			answer += q.top().second.first;
			q.pop();
		}
	}

}


void solve()
{
	int turn = 1;
	while (turn <= m) {
//		cout << turn << "번 실행" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j].first != 0) {
					if (arr[i][j].second == 1) up(i, j);
					else if (arr[i][j].second == 2) down(i, j);
					else if (arr[i][j].second == 3) left(i, j);
					else if (arr[i][j].second == 4) right(i, j);
				}

			}
		}

		calc();
		turn++;
	}
}





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,a,b,c,d;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m >> k;
		memset(arr, 0, sizeof(arr));
		if (!q.empty()) {
			q.pop();
		}

		for (int i = 1; i <= k; i++) {
			cin >> a >> b >> c >> d;
			arr[a][b].first = c;
			arr[a][b].second = d;
			// i를 각 bug의 고유 넘버로 생각하자
		}


		solve();

		answer = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				answer += arr[i][j].first;
			}
		}

		cout << "#" << tc << " " << answer << endl;
	}
	cin >> n >> m;

	return 0;
}