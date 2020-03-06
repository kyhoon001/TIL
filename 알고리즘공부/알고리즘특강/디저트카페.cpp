#include <iostream>
#include <cmath>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;

int tc, n;
int arr[22][22];
int check[22][22];
int num[101];
bool u;
bool l;
int answer;
int ssum;
// 오른쪽으로 2칸 가면 아래로는 3칸이 필요함
// 선 + 1씩 필요.
void calc(int a, int b, int ii, int jj) {
	if (arr[a][b] == 0)
		return;



	memset(check, 0, sizeof(check));
	memset(num, 0, sizeof(num));
	int ta = a;
	int tb = b;
	int cnt = 1;
	check[a][b] = 1;
	num[arr[a][b]] = 1;

	for (int i = 0; i < ii; i++) {
		ta += 1;
		tb += 1;
		if (check[ta][tb] == 0 && num[arr[ta][tb]] == 0 && arr[ta][tb] != 0) { // 탐색 안 했고 안 먹어봤으면
			check[ta][tb] = 1;
			num[arr[ta][tb]] = 1;
			cnt += 1;
		}
		else {
			return;
		}
	}

	for (int i = 0; i < jj; i++) {
		ta += 1;
		tb -= 1;
		if (check[ta][tb] == 0 && num[arr[ta][tb]] == 0 && arr[ta][tb] != 0) { // 탐색 안 했고 안 먹어봤으면
			check[ta][tb] = 1;
			num[arr[ta][tb]] = 1;
			cnt += 1;
		}
		else {
			return;
		}
	}

	for (int i = 0; i < ii; i++) {
		ta -= 1;
		tb -= 1;
		if (check[ta][tb] == 0 && num[arr[ta][tb]] == 0 && arr[ta][tb] != 0) { // 탐색 안 했고 안 먹어봤으면
			check[ta][tb] = 1;
			num[arr[ta][tb]] = 1;
			cnt += 1;
		}
		else {
			return;
		}
	}
	
	for (int i = 0; i < jj; i++) {
		ta -= 1;
		tb += 1;
		if (a == ta && b == tb) {
			break;
		}
		if (check[ta][tb] == 0 && num[arr[ta][tb]] == 0 && arr[ta][tb] != 0) { // 탐색 안 했고 안 먹어봤으면
			check[ta][tb] = 1;
			num[arr[ta][tb]] = 1;
			cnt += 1;
		}
		else {
			return;
		}
	}
	
		answer = max(answer, cnt);
	
	return;
}


void solve(int ii, int jj) {

	// 1,2부터 돌게 됨.
	for (int i = 1; i < n - 1; i++) {
		for (int j = 2; j < n; j++) {

			calc(i, j, ii, jj);
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
		memset(arr, 0, sizeof(arr));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}
		answer = -1;
		//i와 j는 선의 개수를 의미.
		for (int i = 1; i <= n - 2; i++) {
			for (int j = 1; j <= n-2; j++) {
				if (i + j > n - 1) {
					j = n - i - 1;
					solve(i, j);
					break;
				}
				solve(i, j);
			}

		}





		cout << '#' << t << ' ' << answer << endl;
	}
}