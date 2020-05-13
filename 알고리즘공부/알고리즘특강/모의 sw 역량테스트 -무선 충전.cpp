#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int dx[] = { 0,-1,0,1,0 };
int dy[] = { 0,0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc, tmp;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {

		int n, m;
		vector<int> arr[2];
		pair<int, int> p[2];
		cin >> n >> m;  // n은 이동시간 m은 개수
		int answer = 0;

		p[0].first = 0;
		p[0].second = 0;
		p[1].first = 9;
		p[1].second = 9;

		
		///////////////// 사람들 이동 정보.
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> tmp;
				arr[i].push_back(tmp);
			}
		}

		//////////////충전기 정보
		vector<pair<pair<int, int>, pair<int, int>>> v; // 충전기 정보 first = x,y 정보 second = 범위 성능
		int a, b, c, d;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c >> d;
			v.push_back({ {b - 1,a - 1},{c,d} });
		}


		////////////// 이동하며 계산 0 은 가만히 1 = 상 2 = 우 3 = 하 4 = 좌
		for (int i = 0; i <= n; i++) {

			vector<pair<int,int>>q[2];
				for (int k = 0; k < m; k++) { // 충전기
					for (int j = 0; j < 2; j++) { //[j][i]가 이동경로 
						
						int dd = abs(p[j].first - v[k].first.first) + abs(p[j].second - v[k].first.second);
						if (dd <= v[k].second.first) { //충전 범위 안에 있으면.
							q[j].push_back({ v[k].second.second , k }); // 충전량하고 충전기 번호
						}
					}

				}
				///////////계산 부분.
				if(q[0].size() != 0) sort(q[0].rbegin(), q[0].rend());
				if (q[1].size() != 0) sort(q[1].rbegin(), q[1].rend());
				if (q[0].size() != 0 && q[1].size() != 0) {
					if (q[0][0].second == q[1][0].second) { // 둘 다 같은 신호를 받으면
						answer += q[0][0].first;
						if (q[0].size() == 1 && q[1].size() == 1) answer +=0;
						else if(q[0].size() != 1 && q[1].size() != 1) answer += max(q[0][1].first, q[1][1].first);
						else if (q[0].size() == 1 && q[1].size() != 1) answer += q[1][1].first;
						else if (q[0].size() != 1 && q[1].size() == 1) answer += q[0][1].first;


					}
					else {
						answer += q[0][0].first;
						answer += q[1][0].first;
					}
				}
				else if (q[0].size() != 0 && q[1].size() == 0) {
					answer += q[0][0].first;
				}
				else if (q[0].size() == 0 && q[1].size() != 0) {
					answer += q[1][0].first;
				}
				if (n == i) break;
				for (int j = 0; j < 2; j++) {
					p[j].first += dx[arr[j][i]]; // x이동
					p[j].second += dy[arr[j][i]]; // y이동
				}

		}


		cout << "#" << t << " " << answer << endl;
	}



	return 0;
}

