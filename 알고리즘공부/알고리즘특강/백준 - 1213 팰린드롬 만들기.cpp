#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<stack>
using namespace std;

int arr[27];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	int n = s.length();
	bool check = false;
	memset(arr, 0, sizeof(arr));
	string answer = "";
	stack<char> st;
	char c;
	for (int i = 0; i < n; i++) {
		arr[(s[i] - 'A')]++;
	}

	for (int i = 0; i < 27; i++) {
		if (arr[i] % 2 != 0) {
			if (check == false) {
				check = true;
				for (int j = 0; j < arr[i] / 2; j++) {
					answer.push_back(i + 'A');
					st.push(i + 'A');
				}
				c = i + 'A';
			}
			else {
				cout << "I'm Sorry Hansoo" << endl;
				return 0;
			}
		}
		else if (arr[i] % 2 == 0) {
			for (int j = 0; j < arr[i] / 2; j++) {
				answer.push_back(i + 'A');
				st.push(i + 'A');
			}
		}
	}
	if(check == true) answer.push_back(c);
	while (!st.empty()) {
		answer.push_back(st.top());
		st.pop();
	}

	cout << answer << endl;


	return 0;
}