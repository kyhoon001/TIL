#include <iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include <functional>
#include<stack>
using namespace std;

int arr[101][101];
int n;
int na[] = { 1,0,-1,0 };
int nb[] = { 0,1,0,-1 };
int check[101][101];
int answer = 0;
void solve(int a, int b) {
	check[a][b] = 1;

	for (int i = 0; i < 4; i++) {
		int aa = a + na[i];
		int bb = b + nb[i];
		if (aa >= 0 && bb >= 0 && aa < n && bb < n && arr[a][b] == arr[aa][bb] && check[aa][bb] == 0) {
			solve(aa, bb);
		}

	}

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char c;
	cin >> n;
	memset(check, 0, sizeof(check));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			if (c == 'R') {
				arr[i][j] = 1;
			}
			else if (c == 'G') {
				arr[i][j] = 2;
			}
			else {
				arr[i][j] = 3;
			}
		}
	}

	answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0) {
				solve(i, j);
				answer += 1;
			}
		}
	}
	cout << answer << " ";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 2) {
				arr[i][j] = 1;
			}
		}
	}
	memset(check, 0, sizeof(check));
	answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0) {
				solve(i, j);
				answer += 1;
			}
		}
	}


	cout << answer << " ";

	return 0;
}