#include <iostream>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int tc;
long long n, answer;
double e;
vector<pair<long long, pair<long long, long long>>> v;
long long xarr[1001];
long long yarr[1001];
int parent[1001];


long long find(long long a) {
	if (parent[a] == a) {
		return a;
	}
	else {
		return parent[a] = find(parent[a]);
	}
}

void uni(long long a, long long b) {
	a = find(a);
	b = find(b);
	if (a > b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

bool same(long long a, long long b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		return false;
	}
	else {
		return true;
	}
}

void solve() {
	sort(v.begin(), v.end()); // 거리 순으로 정렬해줌.

	for (int i = 0; i < v.size(); i++) {
		if (same(v[i].second.first, v[i].second.second) == false) { // 만약 부모가 같으면 계산 안 함.
			//작은것부터 나가면서 아직 포함 안 되었을 경우 해당 간선을 택함.
			uni(v[i].second.first, v[i].second.second); // 택한 정점들은 같은 부모를 가졌다고 바꿔줌.
			answer += v[i].first;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout << fixed;
	cout.precision(0);

	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		answer = 0;

		while (!v.empty()) {
			v.pop_back();
		}

		for (int i = 0; i < n; i++) {
			cin >> xarr[i];
			parent[i] = i;
		}
		for (int i = 0; i < n; i++) {
			cin >> yarr[i];
		}
		cin >> e;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				long long cnt;
				cnt = (xarr[i] - xarr[j]) * (xarr[i] - xarr[j]) + (yarr[i] - yarr[j]) * (yarr[i] - yarr[j]);

				v.push_back(make_pair(cnt, make_pair(i, j)));

			}
		}

		solve();

		cout << '#' << t << ' ' << (double)(answer * e) << endl;
	
	}
	return 0;
}