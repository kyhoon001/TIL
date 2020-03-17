#include <iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<queue>
#include <functional>
using namespace std;

int tc;
int n;
priority_queue<pair<string, int>> pq;
queue < pair<string, int>> q;
int sett[1000];
string sarr[1000];
int iarr[1000];

void mkset(string s1, string s2,int a) {
	int cnt = 0;
	
	for (int i = 0; i < min(s1.length(), s2.length()); i++) {
		if (s1[i] == s2[i]) {
			cnt += 1;
		}
		else {
			break;
		}
	}
//	cout <<  "cnt : " << cnt << endl;
	sett[a] = cnt;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		string s;
		cin >> s;
		int tmp = 1;
		memset(sett, 0, sizeof(sett));
		bool finish = false;

		for (int i = 1; i <= s.length(); i++) {
			string stmp = "";
			for (int j = i-1; j < s.length(); j++) {
				stmp += s[j];
			}
			pq.push({ stmp,i });
		}


		int itmp = pq.size() - 1;
		for (int i = itmp; i >= 0; i--) {
			sarr[i] = pq.top().first;
			iarr[i] = pq.top().second;
			pq.pop();
		}

//		cout << "itmp : " << itmp << endl;
		for (int i = 0; i < itmp; i++) {
//			cout << tmp << "번째 mkset" << endl;
			mkset(sarr[i], sarr[i + 1], tmp);
			tmp += 1;
		}
//		cout << "size는 : " << s.length() << endl;
		for (int i = 0; i < s.length(); i++) {
//			cout << sarr[i] << "        : " << iarr[i] << "        겹침 : " << sett[i] << endl;
		}
		

		int check = 0;
		int len = s.size();
		cout << "#" << t << " ";
		for (int i = 0; i < len; i++) {
			if (check + (len - iarr[i] + 1) - sett[i] >= n) {
				for (int j = 0; j < n - check + sett[i]; j++) {
					cout << sarr[i][j];
					finish = true;
				}
				break;
			}
			else {
				check += (len - iarr[i] + 1) - sett[i];
			}

		}
		if (finish == false) {
			cout << "none";
		}
		cout << endl;
	}
	return 0;
}