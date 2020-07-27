#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
using namespace std;
int arr[11][11];
int check[11];
int answer = 0;
int tc;
void dfs(int a,int b)
{
	if (a == 11) {
	//	int tmp = 0;
	//	for (int i = 0; i < 11; i++) {
	//		tmp += arr[i][check[i]];
	//		cout << i << "번째 포지션 : " << check[i] << " 의 능력치 : " << arr[i][check[i]] << endl;
	//	}
		answer = max(answer, b);
		return;
	}
	for (int i = 0; i < 11; i++) {
		if (arr[a][i] != 0 && check[i] == 0) {
			check[i] = 1;
			dfs(a + 1, b + arr[a][i]);
			check[i] = 0;
		}
	}

}


int main()
{
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> arr[i][j];
			}
		}
		memset(check, 0, sizeof(check));

		dfs(0, 0);
		cout << answer << endl;
		answer = 0;
	}

	return 0;
}