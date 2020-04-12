#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int d, n, n1, pos, mini;
	cin >> d >> n;
	vector<int> v(d+1);
	vector<int> p(n+1);
	mini = 1000000001;
	for (int i = 1; i <= d; i++) {
		cin >> n1;
		mini = min(n1, mini);
		v[i] = mini;
	}
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	pos = 1;
	for (int i = d; i > 0; i--) {
		if (p[pos] > v[i]) continue;
		pos++;
		if (pos > n) {
			cout << i << endl;
			return 0;
		}
	}
    cout << 0;

	return 0;
}