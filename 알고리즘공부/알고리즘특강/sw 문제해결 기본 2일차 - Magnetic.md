# s/w 문제해결 기본 2일차 - Magnetic

- 주석 참고. brute force

```c++
#include<iostream>
using namespace std;

int arr[101][101] = { 0, };
int n;
int x, y;
int cnt = 0;
int MAX = 100;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (int t = 1; t <= 10; t++) {
		int n;
		cin >> n;

		for (int i = 0; i < MAX; i++) {		//1은 빨강11111111111 위에서 빨강 사라져야함
			for (int j = 0; j < MAX; j++) {	//2는 파랑22222222222 밑에서 파랑 사라져야함
				cin >> arr[i][j];
			}
		}

		for (int j = 0; j < MAX; j++) {
			for (int i = 0; i < MAX; i++) {
				if (arr[i][j] == 1) { // 위에서 세는데 빨강이 나올 때
					break;			  // 멈춘다
				}
				else if (arr[i][j] == 2) {	//위에서 세는데 파랑이 나올 때
					arr[i][j] = 0;          // 삭제해준다
				}
			}
		}

		for (int j = 0; j < MAX; j++) {
			for (int i = MAX-1; i >= 0; i--) {
				if (arr[i][j] == 2) { // 아래서 세는데 파랑이 나올 때
					break;			  // 멈춘다
				}
				else if (arr[i][j] == 1) {	//아래서 세는데 빨강이 나올 때
					arr[i][j] = 0;          // 삭제해준다
				}
			}
		}


		for (int j = 0; j < MAX; j++) {
			int tmp = 0;
			for (int i = 0; i < MAX; i++) {
				if (arr[i][j] == 1 && tmp != 1) { // 위에서 세는데 빨강이 나올 때 그리고 지금까지 센게 빨강이 아니면
					cnt++;			  // 개수 세고
					tmp = 1;
				}
				else if (arr[i][j] == 2 && tmp != 2) {	//위에서 세는데 파랑이 나올 때
					tmp = 2;          // 파랑이라고 저장함
				}
			}
			
		}

		cout << "#" << t << " " << cnt << endl;
		cnt = 0;

	}
	return 0;
}
```

