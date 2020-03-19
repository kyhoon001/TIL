#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

int tc;
int n, answer;
stack<int> s;
bool cansave = false;

void solve(vector<int> arr[],vector<int> check, int a, int cnt) {
	
	for (int i = 0; i < n; i++) {
		if (arr[a][i] == 1 && check[a] == 0) { //갈 수 있고 아직 방문 안 했으면
			check[a] = 1;
			solve(arr, check, i, cnt + 1);
			check[a] = 0;
		}
	}
	answer = max(answer, cnt);
	if (answer == cnt) {
		while (!s.empty()) {
			s.pop();
		}
		cansave = true;
	}
	if (cansave == true) {
		s.push(a);
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		int a, b;
		vector<int> arr[n];
		vector<int> check;
		vector<pair<int, int>> v;

		answer = -1;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			v.push_back({ a,b });
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				check.push_back(0);
				if (i == j) {
					arr[i].push_back(0);
				}
				else if (v[i].second == v[j].first) {
					arr[i].push_back(1);
				}
				else {
					arr[i].push_back(0);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cansave = false;
			solve(arr, check, i, 1);
		}


		cout << "#" << t << " ";
		while (!s.empty()) {
			cout << v[s.top()].first << " " << v[s.top()].second << " ";
			s.pop();
		}
		cout << endl;
	}
	return 0;
}