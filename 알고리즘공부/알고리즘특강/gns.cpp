#include <iostream>
#include<string.h>
#include<algorithm>
#include<string>
using namespace std;

int tc;
int n;
int arr[10];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		string s;
		cin >> s;
		cin >> n;
		cout << s << endl;
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < n; i++) {
			string st;
			cin >> st;

			if (st == "ZRO") arr[0] += 1;
			else if (st == "ONE")arr[1] += 1;
			else if (st == "TWO")arr[2] += 1;
			else if (st == "THR") arr[3] += 1;
			else if (st == "FOR") arr[4] += 1;
			else if (st == "FIV") arr[5] += 1;
			else if (st == "SIX") arr[6] += 1;
			else if (st == "SVN") arr[7] += 1;
			else if (st == "EGT") arr[8] += 1;
			else if (st == "NIN") arr[9] += 1;
		}

//		cout << "#" << t << " " << "\n";

		for (int i = 0; i < n; i++) {
			int j = 0;
			while (arr[j] == 0) {
				j += 1;
			}
			if (j == 0) {
				cout << "ZRO ";
				arr[j] -= 1;
			}
			else if (j == 1) {
				cout << "ONE ";
				arr[j] -= 1;
			}
			else if (j == 2) {
				cout << "TWO ";
				arr[j] -= 1;
			}
			else if (j == 3) {
				cout << "THR ";
				arr[j] -= 1;
			}
			else if (j == 4) {
				cout << "FOR ";
				arr[j] -= 1;
			}
			else if (j == 5) {
				cout << "FIV ";
				arr[j] -= 1;
			}
			else if (j == 6) {
				cout << "SIX ";
				arr[j] -= 1;
			}
			else if (j == 7) {
				cout << "SVN ";
				arr[j] -= 1;
			}
			else if (j == 8) {
				cout << "EGT ";
				arr[j] -= 1;
			}
			else if (j == 9) {
				cout << "NIN ";
				arr[j] -= 1;
			}
		}

		cout << endl;


	
	}
	return 0;
}