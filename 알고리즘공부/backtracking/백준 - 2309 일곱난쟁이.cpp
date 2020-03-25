#include <iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include <functional>
#include<stack>
using namespace std;
int arr[9];
int check = 0;
int u[9];
vector<int> v;

void solve(int a, int num, int cnt) {
	if (cnt > 100) {
		return;
	}
	if (check == 1) {
		return;
	}

	if (num == 7 && cnt == 100 && check == 0) {
		sort(v.begin(), v.end());
		check = 1;
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << endl;
		}
		return;
	}

	for (int i = a; i < 9; i++) {
		if (u[i] == 0) {
			v.push_back(arr[i]);
			u[i] = 1;
			solve(i, num + 1, cnt + arr[i]);
			u[i] = 0;
			v.pop_back();
			if (check == 1) {
				return;
			}
		}
	}

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	memset(u, 0, sizeof(u));
	solve(0, 0, 0);

	return 0;
}