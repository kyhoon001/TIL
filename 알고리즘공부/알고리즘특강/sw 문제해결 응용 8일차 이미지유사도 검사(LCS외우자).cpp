#include <iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
using namespace std;
int t, len;
double answer;
string a, b;
int LCS[510][510];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cout << fixed;
	cout.precision(2);


	cin >> t;
	for (int tc = 1; tc <= t; tc++) {

		cin >> len;
		cin >> a >> b;

		memset(LCS, 0, sizeof(LCS));
		answer = 0;


		//테이블 형식으로 비교하면서 총 몇 개가 겹치는지를 체크해줌.
		for (int i = 1; i <= len; i++) {
			
			for (int j = 1; j <= len; j++) {
				//예를들어 a의 i번째와 b의 j번째까지 최대 몇개가 겹치는지를 2차 테이블에 저장
				//하나씩 증가하면서 비교하다가 a의 i와 b의 j가 같다면 1 늘려주자.
				if (a[i - 1] == b[j - 1]) LCS[i][j] = LCS[i - 1][j - 1] + 1;

				//만약 다르다면 이전까지의 최대값을 사용함.
				else LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);

			}
		}
		answer = (double)LCS[len][len] / (double)len * 100.0;







		cout << "#" << tc << " " << answer << endl;
	}
	

	return 0;
}