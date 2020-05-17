#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
/// 아주 삽질 난리를 쳤음. 원래 2048을 최대로 지정해줬는데
// 2048이 최대값이 아니었음. 더 커져도 됨. 말만 2048게임임.
// 조건을 제대로 안 읽은 잘못.
int arr[51][51];
int n;
int answer = 0;
void up() {


	queue<int> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[j][i] != 0) {
				q.push(arr[j][i]);
				arr[j][i] = 0;
			}
		}
		int idx = 0;
		while (!q.empty()) {
			if (q.size() >= 2) {
				int n1 = q.front();
				q.pop();
				int n2 = q.front();
				if (n1 == n2) {
					arr[idx][i] = n1 * 2;
					q.pop();
					idx++;
				}
				else {
					arr[idx][i] = n1;
					idx += 1;
				}
			}
			else {
				int n1 = q.front();
				q.pop();
				arr[idx][i] = n1;
				idx++;
			}
		}
	}
}


void left() {


	queue<int> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 0) {
				q.push(arr[i][j]);
				arr[i][j] = 0;
			}
		}
		int idx = 0;
		while (!q.empty()) {
			if (q.size() >= 2) {
				int n1 = q.front();
				q.pop();
				int n2 = q.front();
				if (n1 == n2) {
					arr[i][idx] = n1 * 2;
					q.pop();
					idx++;
				}
				else {
					arr[i][idx] = n1;
					idx += 1;
				}
			}
			else {
				int n1 = q.front();
				q.pop();
				arr[i][idx] = n1;
				idx++;
			}
		}
	}


}
void maxi() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 0) {
				answer = max(answer, arr[i][j]);
			}
		}
	}
}


void right() {



	queue<int> q;
	for (int i = 0; i < n; i++) {
		for (int j = n -1 ; j >= 0; j--) {
			if (arr[i][j] != 0) {
				q.push(arr[i][j]);
				arr[i][j] = 0;
			}
		}


		int idx = n - 1;
		while (!q.empty()) {
			if (q.size() >= 2) {
				int n1 = q.front();
				q.pop();
				int n2 = q.front();
				if (n1 == n2) {
					arr[i][idx] = n1 * 2;
					q.pop();
					idx--;
				}
				else {
					arr[i][idx] = n1;
					idx -= 1;
				}
			}
			else {
				int n1 = q.front();
				q.pop();
				arr[i][idx] = n1;
				idx--;
			}
		}
	}



}


void down() {

	queue<int> q;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (arr[j][i] != 0) {
				q.push(arr[j][i]);
				arr[j][i] = 0;
			}
		}
		int idx = n-1;
		while (!q.empty()) {
			if (q.size() >= 2) {
				int n1 = q.front();
				q.pop();
				int n2 = q.front();
				if (n1 == n2) {
					arr[idx][i] = n1 * 2;
					q.pop();
					idx--;
				}
				else {
					arr[idx][i] = n1;
					idx -= 1;
				}
			}
			else {
				int n1 = q.front();
				q.pop();
				arr[idx][i] = n1;
				idx--;
			}
		}
	}
}

void cp(int arr3[][51]) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr3[i][j] = arr[i][j];
		}
	}

}
void rcp(int arr3[][51]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = arr3[i][j];
		}
	}

}

void solve(int a) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) continue;
			cnt = max(cnt, arr[i][j]);
		}
	}
	if ((cnt << (5 - a)) <= answer) return;
	answer = max(answer, cnt);

	if (a == 5) {
		return;
	}
	int arr3[51][51];
	cp(arr3);
	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			up();
			solve(a + 1);
			rcp(arr3);

		}
		else if (i == 1) {
			down();
			solve(a + 1);
			rcp(arr3);
		}
		else if (i == 2) {
			left();
			solve(a + 1);
			rcp(arr3);
		}
		else {
			right();
			solve(a + 1);
			rcp(arr3);
		}


	}


}

void temp(int a) {
	if (a == 0) up();
	else if (a == 1) down();
	else if (a == 2) left();
	else if (a == 3) right();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) continue;
			answer = max(answer, arr[i][j]);
		}
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve(0);

	cout << answer;
	return 0;
}