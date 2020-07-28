#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <map>
using namespace std;
int tc, n;
string arr[100001];
string answer;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> tc;
	for (int t = 0; t < tc; t++) {
		map<string, int> hash;
		answer = "YES";
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			hash[arr[i]] = 1;
		}

		for (int i = 0; i < n; i++) {
			string s1 = "";
			for (int j = 0; j < arr[i].size(); j++) {
				s1 += arr[i][j];
				if (hash[s1] == 1 && s1 != arr[i]) {
					answer = "NO";
					
					break;
				}
			}
			if (answer == "NO") break;
		}

		cout << answer << endl;
	}

	return 0;
}