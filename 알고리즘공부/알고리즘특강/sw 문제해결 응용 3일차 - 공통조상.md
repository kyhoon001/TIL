# s/w 문제해결 응용 3일차 - 공통조상

- 계속 세그먼트 폴트가 났음. 이유는 모름. 공간을 많이 더 주니까 괜찮아짐

```c++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;
int v, e, n1, n2;
int lefts[20000];
int rights[20000];
int path[20000];
int parents[20000];
int answer1, answer2;

void search(int n) {
	
	answer2++;
	
	if (n == 0) {

		return;
	}
	if (lefts[n] == 0 && rights[n] == 0) {

		return;
	}
	

	if (lefts[n] != 0) { // 왼쪽 자식이 있으면
		
		search(lefts[n]);
	}
	if (rights[n] != 0) {
		search(rights[n]);
	}
	return;
}



void find(int n, int c) {
	if (n == 0) {
		return;
	}

	if (path[parents[n]] == 1 && c == 2) {
		answer1 = parents[n];
		
		search(parents[n]);
		return;
		
	}
	if (parents[n] == 1) {
		path[parents[n]]++;
		return;
	}
	else if (parents[n] != 1) { // 만약 부모 노드가 1이 아니면
		path[parents[n]]++; //path에 부모노드를 체크하고
		find(parents[n],c); // 부모노드의 부모노드를 다시 탐색
	}



}




int main() {
//		freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;

	for (int q = 1; q <= tc; q++) {
		cin >> v >> e >> n1 >> n2;
		memset(lefts, 0, 20000);
		memset(rights, 0, 20000);
		memset(path, 0, 20000);
		memset(parents, 0, 20000);
		answer1 = 0;
		answer2 = 0;
		for (int i = 0; i < e; i++) {
			int n;
			int m;
			cin >> n >> m;
			if (lefts[n] == 0) {
				lefts[n] = m;
				parents[m] = n;
			}
			else if (rights[n] == 0) {
				rights[n] = m;
				parents[m] = n;
			}
			
		}
		
		
		find(n1,1);
		find(n2,2);



		cout << "#" << q << " "  << answer1 << " " << answer2 << endl;
	
	}
	return 0;
}
```

