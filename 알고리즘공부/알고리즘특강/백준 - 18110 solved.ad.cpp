#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string.h>
using namespace std;





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;

	
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	vector<int> v(n);
	int n2 = double(n * 0.15 + 0.5);
//	cout << n << endl;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n2; i++) {
		v[i] = 0;
		v[n - 1 - i] = 0;
	}
	double answer = 0;
	for (int i = n2; i < n - n2; i++) {
		answer += v[i];
	}

	answer = (int)double(double(answer / (n - (2 * n2)) + 0.5));
	cout << answer << endl;
	return 0;
}