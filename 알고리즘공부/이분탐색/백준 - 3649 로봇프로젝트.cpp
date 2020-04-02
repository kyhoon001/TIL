#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
int weight, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	while (cin >> weight)
	{

		cin  >> n;
		weight *= 10000000;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());

		int l = 0;
		int r = n - 1;
		while (l < r) {
			int answer = v[l] + v[r];
			if (answer == weight) {
				break;
			}
			else if (answer < weight) {
				l++;
			}
			else {
				r--;
			}
		}
		if (l >= r) {
			cout << "danger" << endl;
		}
		else {
			cout << "yes " << v[l] << " " << v[r] << endl;
		}
	}
}