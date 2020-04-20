#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

int arr[5][5];
int check[25];
int answer = 0;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

bool connect() { // 뽑은 조합이 어 연결이 되어있는지를 확인
	//check[i] 가 1이면 선택되어있는 거임.

	int c2[5][5];
	memset(c2, 0, sizeof(c2));
	int x, y;
	//c2 배열에 누가 누가 선택되었는지를 나타냄. 1은 선택된 사람 0은 안 된 사람.
	for (int i = 0; i < 25; i++) {
		if (check[i] == 1) {
			x = i / 5;
			y = i % 5;
			c2[x][y] = 1;
		}
	}


	queue<pair<int,int>> q;
	q.push({ x,y });
	c2[x][y] = 0;  // 1이 방문해야하는 사람이므로 x,y를 큐에 넣은 뒤 이를 0으로 바꿔서 루프 막음
	int cnt = 1;

	//큐를 돌면서 모두 이어져있는지 확인함.
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int a = x + dx[i];
			int b = y + dy[i];
			if (a >= 0 && b >= 0 && a < 5 && b < 5 && c2[a][b] == 1) {
				q.push({ a,b });
				cnt++;
				c2[a][b] = 0;
			}
		}
	}
	if (cnt == 7) return true; // 만약 총 개수가 7이라면 7명 모두 연결되어 있다는 뜻임.
	return false;
}



void solve(int a, int cnt) {

	if (cnt == 7) { // 7명이 선택되었을 때
		int tmp = 0;


		//뽑은 조합이 맞는지를 확인해야함.
		for (int i = 0; i < 25; i++) {  //4명 이상 소속되었는지 확인
			if (check[i] == 1) {
				tmp += arr[i/5][i%5];
			}
			if (tmp > 3) { // 4명 이상 소속이 안 되었을 시 tmp는 다솜파가 아닌 사람 수
				return; // 끝냄
			}
		}


		//연결이 되어있는지를 connect 함수로 확인
		if (connect() == true) {
			answer++; // 연결되어있으면 answer 하나 추가해줌.
		}
	return;
	}


	

	// 조합을 뽑음.
	for (int i = a; i < 25; i++) {
		if (check[i] == 1) continue;
		check[i] = 1;
		solve(i, cnt+1);
		check[i] = 0;
	}
}





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 이다솜 = 0; 4명 이상이어야함
	// 임도연(y) = 1;
	char c;
	memset(check, 0, sizeof(check));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> c;
			if (c == 'Y') arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}
	solve(0, 0);
	cout << answer << endl;

	
}
