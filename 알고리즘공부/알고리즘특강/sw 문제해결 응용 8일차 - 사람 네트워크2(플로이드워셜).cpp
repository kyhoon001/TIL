#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include<algorithm>
using namespace std;

int tc;
int n, answer;
int arr[1001][1001];




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;

		memset(arr, 999999, sizeof(arr));
		int tmp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> tmp;
				if (tmp == 0) continue;
				arr[i][j] = tmp;
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				if (i == k) continue;
				for (int j = i + 1; j < n; j++) {
					if (j == k || j == i) continue;
					int mini = min(arr[i][j], arr[i][k] + arr[k][j]);

					if (arr[i][j] > mini) {
						arr[i][j] = mini;
						arr[j][i] = mini;
					}
				}

			}
		}




		for (int i = 0; i < n; i++) {
			int semi = 0;
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				semi += arr[i][j];
			}
			if (i == 0) {
				answer = semi;
			}
			else {
				answer = min(semi, answer);
			}

		}


		cout << "#" << t << " " << answer << endl;
	}
	return 0;
}