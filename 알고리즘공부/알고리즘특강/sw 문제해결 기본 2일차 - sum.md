# s/w 문제해결 기본 2일차 - sum

```c++
#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	




	for (int t = 1; t <= 10; t++) {
		int max = 0;
		int c1 = 0;
		int c2 = 0;
		int arr[100][100] = { 0, };
		int trash;
		cin >> trash;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
				
			}
		}

		for (int i = 0; i < 100; i++) {
			int x = 0;
			int y = 0;
			for (int j = 0; j < 100; j++) {
				x += arr[i][j];
				y += arr[j][i];
				
				if (i == j) {
					c1 += arr[i][j];
				}
				else if(j == 99 - i) {
					c2 += arr[i][j];
				}
				
			}
			if (x >= max) {
				max = x;
				//cout << t << " ,   x : " << x;
			}
			if (y >= max) {
				max = y;
				//cout << t << " ,   y : " << y;
			}
			
		}
		
		if (c1 >= max) {
			max = c1;
		}
		if (c2 >= max) {
			max = c2;
		}

		//cout << "c1 : " << c1 << ", c2 : " << c2 << endl;
		cout << "#" << t << " " << max << endl;
	}





	return 0;
}
```

- 여전히 bruteforce