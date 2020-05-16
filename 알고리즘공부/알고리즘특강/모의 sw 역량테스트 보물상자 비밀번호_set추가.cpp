#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<deque>
#include<queue>
using namespace std;
int n, k;
int arr[27];
priority_queue<string> q;
string start;
int answerno = 0;

void sget() {
	for (int i = 0; i < n; i++) {
		int st = i;
		string stmp = "";
		int check = 0;
		while (check != 4) {
			for (int j = 0; j < n / 4; j++) {
				stmp.push_back(start[st]);
				st++;
			}
			q.push(stmp);
			stmp = "";
			check++;
		}
	}
}

void calc(string answer) {
	int a = 1;
	answerno = 0;
	for (int i = 1; i < answer.length(); i++) {
		a *= 16;
	}
	for (int i = 0; i < answer.length(); i++) {
		if (answer[i] - '0' >= 0 && answer[i] - '0' <= 9) {
			answerno += (answer[i] - '0') * a;
		}
		else {
			answerno += (answer[i] - 'A' + 10) * a;
		}
		a /= 16;
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		string answer;
		while (!q.empty()) {
			q.pop();
		}
		start = "";
		cin >> n >> k;
		cin >> start;
		start += start;
		sget();
		int tmp = 1;
		string a = q.top();
		q.pop();
		while (!q.empty()) {
			if (tmp != k) {
				if (a == q.top()) {
					q.pop();
				}
				else if (a != q.top()) {
					a = q.top();
					tmp++;
					q.pop();
				}
			}
			else if (tmp == k) {
				answer = a;
				break;
			}
		}
		calc(answer);


		cout << "#" << t << " " << answerno << endl;
	}

	return 0;
}
// set을 활용해서 풀어본 코드
// 48개 케이스 맞고 2개 틀림. 틀린거 뭔지 모르겠음
/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<deque>
#include<queue>
#include<set>
using namespace std;
int n, k;
int arr[27];
set<string> q;
string start;
int answerno = 0;

void sget() {
	for (int i = 0; i < n; i++) {
		int st = i;
		string stmp = "";
		int check = 0;
		while (check != 4) {
			for (int j = 0; j < n / 4; j++) {
				stmp.push_back(start[st]);
				st++;
			}
			q.insert(stmp);
			stmp = "";
			check++;
		}
	}
}

void calc(string answer) {
	int a = 1;
	answerno = 0;
//	cout << "calc" << endl;
	for (int i = 1; i < answer.length(); i++) {
		a *= 16;
	}
	for (int i = 0; i < answer.length(); i++) {
		if (answer[i] - '0' >= 0 && answer[i] - '0' <= 9) {
			answerno += (answer[i] - '0') * a;
		}
		else {
			answerno += (answer[i] - 'A' + 10) * a;
		}
		a /= 16;
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		string answer;
		q.clear();
		start = "";
		cin >> n >> k >> start;
		start += start;
		sget();

		set<string>::iterator iter;
		if (k == 1) {
			iter = q.end();
			iter--;
			answer = *iter;
	//		cout << answer << endl;
		}
		else {
			int tmp = 0;
			for (iter = q.end(); iter != q.begin(); --iter) {
				if (tmp == k) {
					answer = *iter;
	//				cout << answer << endl;
					break;
				}
				tmp++;
			}
		}
		calc(answer);


		cout << "#" << t << " " << answerno << endl;
	}

	return 0;
}

*/