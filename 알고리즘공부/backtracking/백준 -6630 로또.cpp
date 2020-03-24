#include <iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include <functional>
#include<stack>
using namespace std;

int arr[50];
int check[50];
int n;
vector<int> v;
void solve(int a, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = a; i < n; i++) {
		if (check[i] == 0) {
			v.push_back(arr[i]);
			check[i] = 1;
			solve(i, cnt + 1);
			check[i] = 0;
			v.pop_back();
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> n;
		v.clear();
		if (n == 0) return 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		memset(check, 0, sizeof(check));
		//	for (int i = 0; i < n; i++) {
		solve(0, 0);
		//	}
		cout << endl;
	}
	return 0;
}