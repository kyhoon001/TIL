# s/w 문제해결 기본 2일차 -Ladder1

- 정답에서부터 거꾸로 올라왔음. 세그먼트 폴트로 실행 오류였음. 배열 1 더 크게 줘야함

```c++
#include<iostream>
using namespace std;

int arr[101][101] = { 0, };
int n;
int x, y;
bool goal = false;

void left() {
	if (x < 100 && y < 100 && x >= 0 && y >= 0) { //범위 안에 있으면
		if (arr[x][y - 1] == 1) {
			y -= 1;
			left();
		}
		else {
			//cout << "left   x : " << x << "y : " << y << endl;
			return;
		}
	}

}

void right() {
	if (x < 100 && y < 100 && x >= 0 && y >= 0) { //범위 안에 있으면
		if (arr[x][y + 1] == 1) {
			y += 1;
			right();
		}
		else {
			//cout << "right   x : " << x << "y : " << y << endl;
			return;
		}
	}


}

void up() {
	x -= 1;
	if (x == 0) {
		return;
	}
	else if (arr[x][y - 1] == 1) {
		left();
	}
	else if (arr[x][y + 1] == 1) {
		right();
	}
	up();

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for (int t = 1; t <= 10; t++) {
		int n;
		cin >> n;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
			}
		}


		for (int i = 0; i < 100; i++) { //2에서부터 올라가면서 search하자.
			if (arr[99][i] == 2) {
				x = 99;
				y = i;
			}
		}

		//cout << n << " x : " << x << "y : " << y << endl;
		up();
		cout << "#" << n << " " << y << endl;
		x = 0;
		y = 0;

	}



	return 0;
}
```

