#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int n, x;
int arr[21][21];
int check[21][21];
int answer = 0;

bool possible(int a, int b, int c) { // 위에서 아래로 내려가고 왼쪽에서 오른쪽으로 가는 경우만 생각하자.
	// a부터 시작해야함 c가 1이면 위에서 아래로 2면 왼쪽에서 옆으로
	if (c == 1) {
		for (int i = 0; i < x; i++) {
			if (a + i > n-1 || check[a + i][b] == 1) return false;
			if (arr[a + i][b] != arr[a][b]) {
				return false;
			}
		}

		for (int i = 0; i < x; i++) {
			check[a + i][b] = 1;
		}
	}
	else if (c == -1) {
		for (int i = 1; i < x; i++) {							//////////////= 뻄
			if (a - i < 0 || check[a-i][b] == 1) return false;
			if (arr[a - i][b] != arr[a][b]) {    // 여기 값 다시 줘야함. 그 무어ㅑ arr[a][b]값이 애처에 다름
				return false;
			}
		}

		for (int i = 1; i < x; i++) {				////////////////=
			check[a - i][b] = 1;
		}
	}
	else if(c == 2){
		for (int i = 0; i < x; i++) {
			if (b + i > n-1 || check[a][b+i] == 1) return false;
			if (arr[a][b+i] != arr[a][b]) {
				return false;
			}
		}

		for (int i = 0; i < x; i++) {
			check[a][b+i] = 1;
		}
	}

	else if (c == -2) {
		for (int i = 1; i < x; i++) {			//////////////////
			if (b - i < 0 || check[a][b - i] == 1) return false;
			if (arr[a][b - i] != arr[a][b]) {
				return false;
			}
		}

		for (int i = 0; i < x; i++) {
			check[a][b-i] = 1;
		}
	}



	return true;

}

void down(int a) {
	int start = arr[0][a];
	for (int i = 1; i < n; i++) {
		if (start != arr[i][a]) {
			if (arr[i][a] == start - 1) {
				if (!possible(i, a, 1)) return;

				start = arr[i][a];
				i += x-1;//possible을 해야함

			}else if( arr[i][a] == start + 1) { // 만약 높이가 다르면
				if (!possible(i - 1, a, -1)) return;		/////////////////////
				start = arr[i][a];
				
			}
			else return;	///
		}
	}
//	cout << a << "down" << endl;
	answer++;
}


void right(int a) {
	int start = arr[a][0];
	for (int i = 1; i < n; i++) {
		if (start != arr[a][i]) {
			if (arr[a][i] == start - 1) {
				if (possible(a, i, 2) == false) 
					return;
				
				start = arr[a][i];
				i += x-1;//possible을 해야함
				

			}
			else if (arr[a][i] == start + 1) { // 만약 높이가 다르면
				if (possible(a,i -1, -2) == false) return;		/////////////////////////

				start = arr[a][i];
				
			}
			else return;  ///
		}
	}
	answer++;

}

void solve() {
	for (int i = 0; i < n; i++) {

		down(i);
	}
	memset(check, 0, sizeof(check));
	for (int i = 0; i < n; i++) {

		right(i);
	}
	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		answer = 0;
		cin >> n >> x;
		memset(check, 0, sizeof(check));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}


		solve();

		cout << "#" << tc << " " << answer << endl;
	}

	return 0;
}