# s/w 문제해결 기본 1일차 - View

```c++
#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int num;
	for (int j = 1; j <= 10; j++) {
		cin >> num; // 길이;
		int arr[1000] = {0};
		int lm = 0;
		int rm = 0;
		int result = 0;

		for (int i = 0; i < num; i++) {
			int tmp;
			cin >> tmp;
			arr[i] = tmp;
		}

		for (int i = 2; i < num - 2; i++) {
			if (arr[i - 1] >= arr[i - 2]) {
				lm = arr[i - 1];
			}
			else if (arr[i - 2] > arr[i - 1]) {
				lm = arr[i - 2];
			}

			if (arr[i + 1] >= arr[i + 2]) {
				rm = arr[i + 1];
			}
			else if (arr[i + 2] > arr[i + 1]) {
				rm = arr[i + 2];
			}
			

			if (rm >= lm && arr[i] >= rm) {
				result += arr[i] - rm;
			}
			else if (lm > rm && arr[i] >= lm) {
				result += arr[i] - lm;
			}

		}

		cout << "#" << j << " " << result << endl;

	}
	return 0;

}
```

- 단순한 brute force로 해결

```python
for q in range(10):
    n = int(input())
    s = list(map(int, input().split()))
    cnt = int(0)
    for i in range(2,n-2):
        leftmax = int(0)
        rightmax = int(0)
        if s[i -1] >= s[i-2]:
            leftmax = s[i-1]
        else:
            leftmax = s[i-2]

        if s[i +1] >= s[i+2]:
            rightmax = s[i+1]
        else:
            rightmax = s[i+2]

        if leftmax >= rightmax and leftmax < s[i]:
            cnt += int(s[i]) - int(leftmax)
        elif leftmax <= rightmax and rightmax < s[i]:
            cnt += int(s[i]) - int(rightmax)
    print("#%s %s"%(q+1, cnt))

```

