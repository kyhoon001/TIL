# sw 문제해결 기본 1일차 - Flatten

```c++
#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);


	int dump;
	int cnt = 0;
	int max;
	int maxno = 0;
	int minno = 100;
	for (int j = 1; j <= 10; j++) {
		int arr[101] = { 0 };
		cin >> dump;

		for (int i = 0; i < 100; i++) {
			int tmp;
			cin >> tmp;
			arr[tmp]++;
		}

		//여기까지 해서 배열에 넣음. 정렬된 상태. 


		for (int i = 100; i > 0; i--) {
			if (arr[i] != 0) {
				max = i;
				break;
			}
		}
		// max를 식별하는 것. 

		for (int d = 0; d < dump; d++) {
			if (arr[max] == 0) {
				for (int i = max; i > 0; i--) {
					if (arr[i] != 0) {
						max = i;
						break;
					}
				}
			}

			if (arr[cnt] == 0) {
				for (int i = cnt; i <= 100; i++) {
					if (arr[i] != 0) {
						cnt = i;
						break;
					}
				}
			}



			if (arr[cnt] != 0) {
				if (arr[max] != 0) {
					arr[cnt] -= 1;
					arr[cnt + 1] += 1;
					arr[max] -= 1;
					arr[max - 1] += 1;
				}
				
			}
			
		}

		for (int i = 0; i <= 100; i++) {
			if (arr[i] != 0 && i >= maxno)
				maxno = i;
			if (arr[i] != 0 && i <= minno)
				minno = i;
		}

		cout << "#" << j << " " << maxno - minno << endl;
		max = 0;
		maxno = 0;
		minno = 100;
		cnt = 0;

	}

	return 0;

}
```

-  brute force

```python
for q in range(10):
    n = int(input())
    s = list(map(int, input().split()))
    cnt = int(0)
    a = []
    sm = 101
    big = 0
    for i in range(101):
        a.append(int(0))
    for c in s:
        a[c] +=1
        if c < sm:
            sm = c
        elif c > big:
            big = c

    while n != 0:
        if a[sm] == 0:
            sm += 1
        if a[big] == 0:
            big -= 1
        a[sm] -=1
        a[sm+1] +=1
        a[big] -=1
        a[big-1] +=1
        n-=1
        
    if a[sm] == 0:
        sm += 1
    if a[big] == 0:
        big -= 1

    print("#%s %s"%(q+1,big - sm))
```

