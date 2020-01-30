# s/w 문제해결 기본 4일차 -길찾기

```c++
#include<iostream>
#include<string>
using namespace std;

const int MAX = 101;


int c, n;
int n1, n2;
bool check = false;
int arr[MAX][2];

void find(int x) {
	if (arr[x][0] == 99 || arr[x][1] == 99 && check == false) {
		check = true;
		return;
	}

	if (check == false) {
		if (arr[x][0] != 0) {
			find(arr[x][0]);
		}
		if (arr[x][1] != 0) {
			find(arr[x][1]);
		}
	}



}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int t = 1; t <= 10; t++) {
		cin >> c >> n;


		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < 2; j++) {
				arr[i][j] = 0;
			}
		}

		
		for (int i = 0; i < n; i++) {
			cin >> n1 >> n2;
			if (arr[n1][0] == 0) {
				arr[n1][0] = n2;
			}
			else
				arr[n1][1] = n2;

		}
		find(0);

		if (check == true) {
			cout << "#" << c << " " << 1 << endl;
		}
		else {
			cout << "#" << c << " " << 0 << endl;
		}
		check = false;

	}


	return 0;
}
```

- 배열을 초기화하는 것을 까먹어서 오류가 발생했었음.