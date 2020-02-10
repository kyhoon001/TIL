# s/w 문제해결 기본 9일차 - 사칙연산 입출력 다시보기 중요

- stoi 사용했음
- 문자열 입출력 공부 필요
- => string 타입은 띄어쓰기 못 받음. 받고 싶으면 getline(cin,s) 써야함
- 1 - 2 3 에서  int 값을 하나 받고 string으로 하나 받으니까 -만 값이 받아졌음.

```c++
#include <iostream>
#include<string>
#include<stack>

using namespace std;
int n;
double arr[1001];
int l[1001];
int r[1001];
int q = 1;
string answer;
stack<double> num1;

void mk(int a) {
	if (l[a] != 0) { // l이 비어있지 않다면
		mk(l[a]); // 왼쪽거 호출.
	}
	if (r[a] != 0) {
		mk(r[a]);
	}

	if (arr[a] == -1) {
		double n1, n2;
		n2 = num1.top();
		num1.pop();
		n1 = num1.top();
		num1.pop();
		num1.push(n1 + n2);
		answer += '+';
	}
	else if (arr[a] == -2) {
		double n1, n2;
		n2 = num1.top();
		num1.pop();
		n1 = num1.top();
		num1.pop();
		num1.push(n1 - n2);
		answer += '-';
	}
	else if (arr[a] == -3) {
		double n1, n2;
		n2 = num1.top();
		num1.pop();
		n1 = num1.top();
		num1.pop();
		num1.push(n1 * n2);
		answer += '*';
	}
	else if (arr[a] == -4) {
		double n1, n2;
		n2 = num1.top();
		num1.pop();
		n1 = num1.top();
		num1.pop();
		num1.push(n1 / n2);
		answer += '/';
	}
	else {
		answer += to_string(int(arr[a]));
		num1.push(arr[a]);
	}
}

void solve(int a) {
	mk(a);
	cout << "#" << q << " " << int(num1.top()) << endl;
	num1.pop();
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (q = 1; q <= 10; q++) {
		cin >> n;
		answer = "";
		while (!num1.empty()) {
			num1.pop();
		}
		for (int i = 0; i < 1001; i++) {
			arr[i] = 0;
			l[i] = 0;
			r[i] = 0;
		}

		for (int i = 0; i < n; i++) {
			int a;
			string c;
			cin >> a >> c;
			if (c[0] != '-' && c[0] != '*' && c[0] != '/' && c[0] != '+') {
				arr[a] = stoi(c);
			}
			else {
				// + - * /   -1 -2 -3 -4
				if (c[0] == '-') {
					arr[a] = -2;
				}
				else if (c[0] == '*') {
					arr[a] = -3;
				}
				else if (c[0] == '/') {
					arr[a] = -4;
				}
				else if (c[0] == '+') {
					arr[a] = -1;
				}
				int ltmp, rtmp;
				cin >> ltmp >> rtmp;
				l[a] = ltmp;
				r[a] = rtmp;
			}
		}
		solve(1);
	}

		return 0;
}
```

