#include <iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

#define ABS(x) ( x > 0 ? x : - (x) )
int tc, answer, n;
int arr[17][17];
int check[17];


void count() {
	int tmp = 0;
	int tmp2 = 0;
	vector<int> v[2];

	for (int i = 0; i < n; i++) {
		if (check[i] == 0)
			v[0].push_back(i);
		else if (check[i] == 1)
			v[1].push_back(i);
	}
		
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			if (i == j) {
				continue;
			}
			tmp += arr[v[0][i]][v[0][j]];
		}
	}
	
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			if (i == j) {
				continue;
			}
			tmp2 += arr[v[1][i]][v[1][j]];
		}
	}

	answer = min(answer, ABS(tmp - tmp2));

}

void solve(int a, int cnt) {
	if (cnt == n / 2) {
		count();
		return;
	}
	for (int i = a; i < n; i++) { // 시간을 단축하기 위함
		if (check[i] == 0) {
			check[i] = 1;
			solve(i, cnt + 1);
			check[i] = 0;
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		answer = 60000;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		solve(0,0);

		cout << '#' << t << ' ' << answer << endl;

	}
}