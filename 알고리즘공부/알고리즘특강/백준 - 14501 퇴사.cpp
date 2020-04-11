#include <iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
using namespace std;

int n, answer;
vector<pair<int, int>> v;
int check[16];
void solve(int a,int day, int cnt) {
	if (a + day > n) {
		return;
	}
//	cout << "a : " << a << "실행" << endl;
	answer = max(answer, cnt);

	for (int i = a + day; i < v.size(); i++) {
		if (check[i] == 0 && a + day + v[i].first <= n) {
//			cout << "값 : " << a + day + v[i].first << "          " << a << endl;
			check[i] = 1;
			solve(i, v[i].first, cnt + v[i].second);
			check[i] = 0;

		}
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int n1, n2;
	memset(check, 0, sizeof(check));
	for (int i = 0; i < n; i++) {
		cin >> n1 >> n2;
		v.push_back({ n1,n2 });
	}

	for (int i = 0; i < n; i++) {
		check[i] = 1;
		solve(i, v[i].first, v[i].second);
		check[i] = 0;
	}
	cout << answer << endl;

	return 0;
}