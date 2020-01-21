# c로 구현한 부분집합 만드는 코드 비트 연산 기반



```c
#include <stdio.h>

int main(void) {
	// your code goes here
	int i, j;
	int arr[] = {3,6,7,1,5,4};
	int n = sizeof(arr)/sizeof(arr[0]); // n은 원소의 개수를 의미.
	
	for(int i = 0; i <(1<<(n)); i++) { //1 <<n : 부분집합의 개수
		for(int j = 0; j < n; j++) {
			if(i&(1<<j))	//i의 j번째 비트가 1이면 j번째 원소 출력
			printf("%d, ",arr[j]);
		}
		printf("\n");
	}
	
	return 0;
}

```

