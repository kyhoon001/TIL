#include <iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

vector<int> v[1010];
int check[1010];
int n, m;
int answer = 0;

void solve(int a) {

	check[a] = 1;
    

	for (int i = 0; i < v[a].size(); i++) {
		if (check[v[a][i]] == 0) {
            
			solve(v[a][i]);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int n1, n2;
	memset(check, 0, sizeof(check));
	
	for (int i = 0; i < m; i++) {
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
		
	}
	answer = 0;
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
				solve(i);
				answer += 1;
		}
	}
	cout << answer << endl;

	return 0;
}