# s/w 문제해결 기본 1일차 - 최빈수 구하기

```c++
#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n;
	cin >> n;

	for (int j = 1; j <= n; j++) {
		int d;
		cin >> d;
		int cnt[101] = { 0 };
		int max = 0;
		int mi = 0;
		for (int i = 0; i < 1000; i++) {
			int num;
			cin >> num;
			cnt[num]++;
		}

		for (int i = 0; i <= 100; i++) {
			int num = cnt[i];
			if (cnt[i] >= max) {
				max = cnt[i];
				mi = i;
			}
		}
		cout << "#" << j << " " << mi << endl;

	}




	return 0;

}
```

- brute force. 그리고 d 는 그냥 쓸모없는 값.


```python

c = int(input())
for i in range(c):
    t = input()
    arr = input().split()
    b = []
    mini = 0
    for j in range(101):
        b.append(int(0))

    for j in arr :
         b[int(j)] += int(1)
    for j in range(1,101):
        if b[j] >= b[mini] :
            mini = j
    print("#%s %s"%(t, mini))

```

