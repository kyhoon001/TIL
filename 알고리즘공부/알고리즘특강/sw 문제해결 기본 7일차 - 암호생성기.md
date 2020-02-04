# s/w 문제해결 기본 7일차 - 암호생성기

```c++
#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<queue>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n[8];
	for (int t = 0; t < 10; t++) {
		int c;
		cin >> c;
		int num = 1;
		for (int i = 0; i < 8; i++) {
			cin >> n[i];
		}

		bool answer = false;
		while(!answer) {
			for (int i = 0; i < 8; i++) {
				n[0] -= num;
				if (n[0] <= 0) {
					cout << "#" << c << " ";
					for (int j = 1; j < 8; j++) {
						cout << n[j] << " ";
					}
					cout << 0 << endl;
					answer = true;
					break;
				}
				int tmp = n[0];
				n[0] = n[1];
				n[1] = n[2];
				n[2] = n[3];
				n[3] = n[4];
				n[4] = n[5];
				n[5] = n[6];
				n[6] = n[7];
				n[7] = tmp;
				if (num == 5) {
					num = 1;
				}
				else
					num++;
			}
		}

	}
	return 0;
}
```

