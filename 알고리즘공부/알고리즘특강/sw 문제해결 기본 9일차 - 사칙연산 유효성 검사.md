# s/w 문제해결 기본 9일차 - 사칙연산 유효성 검사

- 0을 나누거나 0으로 나누는 예외를 처리 안 해서 오래걸렸음

```c++
#include <iostream>
#include<string>
#include<stack>

using namespace std;

int n;
int arr[201];
int l[201];
int r[201];
int q = 1;
stack<int> st;
bool answer = true;





void solve(int a) {
	if (l[a] != 0) {
		solve(l[a]);
	}
	if (r[a] != 0) {
		solve(r[a]);
	}
	
	if (arr[a] >= 0 && arr[a] <= 9) {
		st.push(arr[a]);
	}

	else if (arr[a] == -1) {
		if (st.size() < 2) {
			answer = false;
			return;
		}
		int n1, n2;
		n1 = st.top();
		st.pop();
		n2 = st.top();
		st.pop();
		st.push(n2 + n1);

	}
	else if (arr[a] == -2) {
		if (st.size() < 2) {
			answer = false;
			return;
		}
		int n1, n2;
		n1 = st.top();
		st.pop();
		n2 = st.top();
		st.pop();
		st.push(n2 - n1);

	}
	else if (arr[a] == -3) {
		if (st.size() < 2) {
			answer = false;
			return;
		}
		int n1, n2;
		n1 = st.top();
		st.pop();
		n2 = st.top();
		st.pop();
		st.push(n2 * n1);

	}
	else if (arr[a] == -4) {
		if (st.size() < 2) {
			answer = false;
			return;
		}
		int n1, n2;
		n1 = st.top();
		st.pop();
		n2 = st.top();
		st.pop();
		if (n2 == 0) {
			n2 = 1;
		}
		if (n1 == 0) {
			n1 = 1;
		}
		st.push(n2 / n1);

	}
}














int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (; q <= 10; q++) {
		answer = true;
		while (!st.empty()) {
			st.pop();
		}

		cin >> n;

		for (int i = 0; i < 201; i++) {
			arr[i] = 0;
			l[i] = 0;
			r[i] = 0;
		}




		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			string s;
			getline(cin, s);
			bool check = false;
			bool rcheck = false;

			for (int j = 1; j < s.length(); j++) {

				if (s[j] == '+') {
					arr[num] = -1;
				}
				else if (s[j] == '-') {
					arr[num] = -2;
				}
				else if (s[j] == '*') {
					arr[num] = -3;
				}
				else if (s[j] == '/') {
					arr[num] = -4;
				}
				else {
					if (check == false && s[j] != ' ') {
						arr[num] *= 10;
						arr[num] += s[j] - '0';
					}
					else if (s[j] == ' ' && check == false) {
						check = true;
					}
					else if (check == true && s[j] != ' ' && rcheck == false) {
						l[num] *= 10;
						l[num] += s[j] - '0';
					}
					else if (s[j] == ' ' && check == true && l[num] != 0) {
						rcheck = true;
					}
					else if (rcheck == true && s[j] != ' ') {
						r[num] *= 10;
						r[num] += s[j] - '0';
					}


				}

			}

		}
		solve(1);
		if (answer == false) {
			cout << "#" << q << " 0" << endl;
		}
		else
			cout << "#" << q << " 1" << endl;
	}
		return 0;

}
```

