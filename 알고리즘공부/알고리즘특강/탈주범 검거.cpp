#include <iostream>
#include <cmath>
#include<string.h>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

int tc, n,m,r,c,l,answer;
int arr[51][51];
int check[51][51];
queue<pair<int, int>> q;


void c_up(int a, int b) {
	int nx = a - 1;
	if (nx >= 0 && b >= 0 && nx < n && b < m) {
		if (check[nx][b] == 0 && arr[nx][b] != 0) {
			if (arr[nx][b] == 1 || arr[nx][b] == 2 || arr[nx][b] == 5 || arr[nx][b] == 6) {
				q.push({ nx, b });
				check[nx][b] = 1;
			}
		}
	}
}
void c_down(int a, int b) {
	int nx = a + 1;
	if (nx >= 0 && b >= 0 && nx < n && b < m) {
		if (check[nx][b] == 0 && arr[nx][b] != 0) {
			if (arr[nx][b] == 1 || arr[nx][b] == 2 || arr[nx][b] == 4 || arr[nx][b] == 7) {
				q.push({ nx, b });
				check[nx][b] = 1;
			}
		}
	}
}
void c_right(int a, int b) {
	int ny = b + 1;
	if (a >= 0 && ny >= 0 && a < n && ny < m) {
		if (check[a][ny] == 0 && arr[a][ny] != 0) {
			if (arr[a][ny] == 1 || arr[a][ny] == 3 || arr[a][ny] == 7 || arr[a][ny] == 6) {
				q.push({ a, ny });
				check[a][ny] = 1;
			}
		}
	}
}
void c_left(int a, int b) {
	int ny = b - 1;

	if (a >= 0 && ny >= 0 && a < n && ny < m) {
		if (check[a][ny] == 0 && arr[a][ny] != 0) {
			if (arr[a][ny] == 1 || arr[a][ny] == 3 || arr[a][ny] == 4 || arr[a][ny] == 5) {
				q.push({ a, ny });
				check[a][ny] = 1;
			}
		}
	}
}

void chk(int a, int b) {
	if (arr[a][b] == 1) {
		c_up(a, b);
		c_down(a, b);
		c_left(a, b);
		c_right(a, b);

	}
	else if (arr[a][b] == 2) {
		c_up(a, b);
		c_down(a, b);

	}
	else if (arr[a][b] == 3) {
		c_left(a, b);
		c_right(a, b);
	}
	else if (arr[a][b] == 4) {
		c_up(a, b);
		c_right(a, b);
	}
	else if (arr[a][b] == 5) {
		c_down(a, b);
		c_right(a, b);
	}
	else if (arr[a][b] == 6) {
		c_down(a, b);
		c_left(a, b);
	}
	else if (arr[a][b] == 7) {
		c_up(a, b);
		c_left(a, b);
	}
}

void solve(int cnt) { // cnt 초기값은 1로 줘야함.


	while (cnt != l) {
		int a = q.size();
//		cout << a << endl;
		for (int i = 0; i < a; i++) {
			int na = q.front().first;
//			cout << "na" << endl;
			int nb = q.front().second;
//			cout << "1 : " << q.front().first << "    " << q.front().second << endl;
			q.pop();
//			if(!q.empty())
//				cout << q.front().first << "    " << q.front().second << endl;
			chk(na, nb);
		}
		cnt += 1;
	}
	int sum = 0;
//	cout << endl << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
//			cout << check[i][j] << " ";
			sum += check[i][j];
		}
//		cout << endl;
	}
//	cout << endl << endl;
	answer = sum;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		while (!q.empty()) {
			q.pop();
		}
		cin >> n >> m >> r >> c >> l;
		memset(check, 0, sizeof(check));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
		}
		if (l == 1) {
			cout << '#' << t << " 1" << endl;
			continue;
		}
		q.push({ r,c });
		check[r][c] = 1;
		solve(1);

		cout << '#' << t << ' ' << answer << endl;

	}
}