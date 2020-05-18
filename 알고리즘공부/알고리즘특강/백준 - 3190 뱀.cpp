#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
using namespace std;


deque<pair<int, int>> q;
int n, k, l, arr[110][110];
vector<pair<int, char>> v;
int answer = 1;

void move(int c) { // c 는 상하좌우 알려주자 벽이나 지랑 박으면 끝남.
	int a = q.front().first;
	int b = q.front().second;
	int tmp = 0;
	int i = 0;
	while (1) {
		if (i < v.size() && tmp == v[i].first) {
			//상하좌우
			if ((c == 1 && v[i].second == 'L') || (c == 0 && v[i].second == 'D')) c = 2;
			else if ((c == 0 && v[i].second == 'L') || (c == 1 && v[i].second == 'D')) c = 3; 
			else if ((c == 2 && v[i].second == 'L') || (c == 3 && v[i].second == 'D')) c = 0; 
			else if ((c == 3 && v[i].second == 'L') || (c == 2 && v[i].second == 'D')) c = 1;
			i++;
		}
		if (c == 0) b -= 1; // 왼쪽으로 기어간다는 뜻.
		else if (c == 1) b += 1; //오른쪽으로 기어간다는 뜻
		else if (c == 2) a -= 1; // 위쪽으로 기어간다는 뜻.
		else a += 1; // 아래로 기어간다는 뜻.


		if (a >= 0 && b >= 0 && a < n && b < n && arr[a][b] != 1) { // 안 죽을 때. 범위안에 안 들고 몸도 아님.
			if (arr[a][b] == 0) { // 암것도 없으면
				arr[q.back().first][q.back().second] = 0; // 꼬리를 0으로 바꿔줌.
				q.pop_back(); // 꼬리 줄임
				q.push_front({ a,b }); // 대가리 늘리고
				arr[a][b] = 1; // 대가리 표시
			}
			else if (arr[a][b] == 2) { // 사과가 있을 경우
				q.push_front({ a,b }); // 대가리만 늘림.
				arr[a][b] = 1; // 대가리 표시.
			}
			tmp++;
			answer++;
		}
		else { // 아닐경우 죽음.
			return;
		}
	}

}



// 0 1 2 3 상하좌우;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	memset(arr, 0, sizeof(arr));
	q.push_front({ 0,0 });
	arr[0][0] = 1;
	for (int i = 0; i < k; i++) { // 사과가 있으면 2임.
		int a, b;
		cin >> a >> b;
		a--; 
		b--;
		arr[a][b] = 2; 
	}
	cin >> l;
	for (int i = 0; i < l; i++) { // L은 왼쪽으로 90도 D면 오른쪽으로 90도 대가리 바꿈.
		int a;
		char b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	int dir  = 1; // 좌우상하
	int tmp = 0;
	move(dir);
	cout << answer << endl;
	return 0;
}
