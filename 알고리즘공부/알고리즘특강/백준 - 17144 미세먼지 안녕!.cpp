#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <map>
using namespace std;
int r, c, t;

int arr[51][51];
int arr2[51][51];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1, - 1 };

pair<int, int> top;
pair<int, int> bot;


void diffuse()
{
	//확산
	memset(arr2, 0, sizeof(arr2));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] != 0) {
				int cnt = arr[i][j] / 5;

				int n = 0;
				for (int z = 0; z < 4; z++) {
					int na = i + dx[z];
					int nb = j + dy[z];
					if (na >= 0 && nb >= 0 && na < r && nb < c && arr[na][nb] != -1) {
						arr2[na][nb] += cnt;
						n++;
					}
				}
				arr2[i][j] += arr[i][j] - (n * cnt);
			}
		}
	}
	// arr을 확산된 상태로 바꿔줌
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			arr[i][j] = arr2[i][j];
		}
	}
}

void air() {
	int a = top.first;
	int b = top.second + 1; // 처음은 오른쪽에서 시작하기 위해서
	
	int dir = 0; // 0 = 오른쪽 1 = 위 2 = 왼 3 = 아래
	int pre = 0;
	int tmp;
	while (1) {
		if (a == top.first && b == top.second) break;

		if (b + 1 == c) dir = 1;
		if(a == 0) dir = 2;
		if(b == 0) dir = 3;



		tmp = arr[a][b];
		arr[a][b] = pre;
		pre = tmp;
		
		if (dir == 0) b++;
		else if (dir == 1) a--;
		else if (dir == 2) b--;
		else if (dir == 3) a++;

	}

	a = bot.first;
	b = bot.second + 1;
	dir = 0; // 0 = 오른쪽 1 = 아래쪽 2 = 왼쪽 3= 위쪽
	pre = 0;
	tmp = 0;

	while (1) {
		if (a == bot.first && b == bot.second) break;

		if (b + 1 == c) dir = 1;
		if (a +1 == r) dir = 2;
		if (b == 0) dir = 3;



		tmp = arr[a][b];
		arr[a][b] = pre;
		pre = tmp;

		if (dir == 0) b++;
		else if (dir == 1) a++;
		else if (dir == 2) b--;
		else if (dir == 3) a--;

	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> r >> c >> t;
	memset(arr, 0, sizeof(arr));
	memset(arr2, 0, sizeof(arr2));

	bool check = false;
	for (int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1 && check == false) {
				top = { i,j };
				bot = { i + 1, j };
				check = true;
			}
		}
	}



	while (t) {
		t--;
		diffuse();
		air();
	}
	int answer = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] != -1) answer += arr[i][j];
		}
	}
	cout << answer << endl;

	return 0;
}