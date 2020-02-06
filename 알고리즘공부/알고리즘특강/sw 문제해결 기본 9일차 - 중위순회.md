# s/w 문제해결 기본 9일차 - 중위순회

```  c++
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int leftarr[101];
int rightarr[101];
char a[101];

void solve(int n) {
	if (leftarr[n] == 0) {
		cout << a[n];
		return;
	}
	else if (leftarr[n] != 0) {
		solve(leftarr[n]);
		cout << a[n];
	}
	 // 왼쪽 다 출력하고 자기 출력
	if (rightarr[n] != 0) {
		solve(rightarr[n]);
	}

}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	for (int t = 1; t <= 10; t++) {
		for (int i = 0; i < 101; i++) { // 초기화. 
			leftarr[i] = 0;
			rightarr[i] = 0;
			a[i] = 0;
		}
		cin >> n;
		if (n % 2 == 0) { //짝수라면
			for (int o = 1; o <= n; o++) { //네번씩 받고
				int no, leftno, rightno;
				char alpha;
				if (o < n / 2) {
					cin >> no >> alpha >> leftno >> rightno; //입력 끝.
					leftarr[no] = leftno;
					rightarr[no] = rightno;
					a[no] = alpha;
				}
				else if (o == n / 2) { //2의 배수이면 왼쪽까지 있음.
					cin >> no >> alpha >> leftno; //입력 끝.
					leftarr[no] = leftno;
					a[no] = alpha;
				}
				else {
					cin >> no >> alpha; //입력 끝.
					a[no] = alpha;
				}

			}
		}
		else if (n % 2 == 1) { //짝수라면
			for (int o = 0; o < n; o++) { //네번씩 받고
				int no, leftno, rightno;
				char alpha;
				if (o < n / 2) {
					cin >> no >> alpha >> leftno >> rightno; //입력 끝.
					leftarr[no] = leftno;
					rightarr[no] = rightno;
					a[no] = alpha;
				}
				else {
					cin >> no >> alpha; //입력 끝.
					a[no] = alpha;
				}

			}
		}
		
		cout << "#" << t << " ";
		solve(1);
		cout << endl;

	}


	return 0;
}
```

- 입력받는 것을 손보면 더 줄일 수 있을듯.