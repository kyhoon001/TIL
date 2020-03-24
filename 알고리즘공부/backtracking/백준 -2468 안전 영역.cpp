#include <iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include <functional>
#include<stack>
using namespace std;

int arr[101][101];
int check[101][101];
int arr2[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int answer,cnt;
int n, top;


void solve(int a, int b) {

	check[a][b] = 1;
	for (int i = 0; i < 4; i++) {
		int na = a + dx[i];
		int nb = b + dy[i];

		if (na >= 0 && nb >= 0 && na < n && nb < n && check[na][nb] == 0 && arr2[na][nb] == 0) {

			solve(na, nb);
		}
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	top = -1;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			arr[i][j] = tmp;
			top = max(top, tmp);
		}
	}

	for (int t = 0; t <= top; t++) {
        
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] > t) {
					arr2[i][j] = 0;
				}
				else
					arr2[i][j] = 1;
			}
		}
        
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr2[i][j] != 1 && check[i][j] == 0) {
					solve(i, j);
					cnt += 1;
				}
			}
		}
	memset(check, 0, sizeof(arr));
	answer = max(answer, cnt);
	cnt = 0;
	}
	cout << answer << endl;

	

	return 0;
}