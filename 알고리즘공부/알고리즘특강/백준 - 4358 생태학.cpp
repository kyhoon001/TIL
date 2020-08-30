// map을 사용해서 풀이했음.
// 나중에 Trie를 사용해서 한 번 풀어보고 싶음.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <map>
#include <queue>
using namespace std;

map<string, double> hmap;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s;
	int cnt = 0;
	while (getline(cin, s)) {
		if (s == "") break;
		hmap[s] += 1;
		cnt++;
	}
	map<string, double> ::iterator iter = hmap.begin();
	// 소수점 자리수 수정
	cout << fixed;
	cout.precision(4);
	/////////////////////
	for (iter = hmap.begin(); iter != hmap.end(); ++iter) {
		cout << (*iter).first << " " << (double)((*iter).second / cnt) * 100 << endl;
	}

	return 0;
}