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
	
	int n, h, answer;
	cin >> n >> h;
	vector<int> up(n/2);
	vector<int> down(n/2);
	for (int i = 0; i < n / 2; i++) {
		cin >> up[i] >> down[i];
	}
	sort(up.begin(), up.end());
	sort(down.begin(), down.end());
	int cnt = 1;
	answer = 3000000;
	for (int i = 1; i <= h; i++) {
		int tmp = down.size() - (lower_bound(down.begin(), down.end(), i) - down.begin());
		//bound는 주소와 관련된 연산이므로 항상 처음을 빼줘야 함
		tmp += up.size() - (upper_bound(up.begin(), up.end(), h - i) - up.begin());
		//tmp에는 총 부숴야하는 개수가 저장되어 있음.

		if (answer > tmp) {
			answer = tmp;
			cnt = 1;
		}
		else if (answer == tmp) {
			cnt += 1;
		}
		
		
	}

	cout << answer << " " << cnt << endl;

	return 0;
}