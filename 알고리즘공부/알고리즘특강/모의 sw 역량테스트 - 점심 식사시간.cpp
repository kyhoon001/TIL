#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int arr[11][11];
int answer, n;
int parr[11];
vector<pair<int, int>> stair,people;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		stair.clear();
		people.clear();
		memset(parr, 0, sizeof(parr));
		answer = 10000;
		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (arr[i][j] != 0 && arr[i][j] != 1) {////////계단 받음
					stair.push_back({ i,j });
				}
				else if (arr[i][j] == 1) { //////////// 사람 받음.
					people.push_back({ i,j });
				}
			}
		}

		for (int i = 0; i < (1 << (people.size())); i++) {
			for (int j = 0; j < people.size(); j++) {
				if (i&(1 << j)) parr[j] = 1;
				else parr[j] = 0;
			}

			int cnt[2];
			for (int j = 0; j < 2; j++) {
				vector<pair<int,int>> q;
				cnt[j] = 0;
				
				for (int k = 0; k < people.size(); k++) {
					if (parr[k] == j) { // 0이면 0 1이면 1
						int a = abs(people[k].first - stair[j].first) + abs(people[k].second - stair[j].second) + 1;
						q.push_back({ a, a + arr[stair[j].first][stair[j].second] });// 처음에는 도착 순서 두번째는 나가는 순서
	
					}
				}
				///////////////////////////////////////////////계단 큐에 넣었음. 도착하는 순서대로 적혀있음.
				sort(q.begin(), q.end());

				if (q.size() == 0) continue;

				if (q.size() <= 3) {
					cnt[j] = q[q.size() - 1].second;
					continue;
				}
				queue<int>timeq;
				timeq.push(q[0].second);
				timeq.push(q[1].second);
				timeq.push(q[2].second);
				int time = q[0].second;
				for (int k = 3; k < q.size(); k++) {
					if (timeq.size() >= 3) {
						time = timeq.front();
						timeq.pop();
					}
					if(q[k].first < time) timeq.push(time + arr[stair[j].first][stair[j].second]); // 시간보다 먼저 와서 기다릴때
					else timeq.push(q[k].first + arr[stair[j].first][stair[j].second]);
				}
				while (!timeq.empty()) {
					time = timeq.front();
					timeq.pop();
				}
				cnt[j] = time;

			}
			int tmp = max(cnt[0], cnt[1]);
			answer = min(answer, tmp);

		}





		cout << "#" << t << " " << answer << endl;
	}
	

	return 0;
}









