#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
long long n;
int k, q;
//왜 안 되는지 모르겠음
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long a, b, cnt;
	cin >> n >> k >> q;

	for (int i = 0; i < q; i++) {
		cin >> a >> b;

		cnt = 0;

		if (k == 1) {
			cout << abs(a - b) << '\n';
			continue;
//			cnt = abs(a - b);
		}
//		else {
			while (a != b) {
				//			cout << "a : " << a << endl;
				//			cout << "b : " << b << endl;
//				if (a > b) {
//					a = (a - 2) / k + 1;
//				}
//				else {
//					b = (b - 2) / k + 1;
//				}
				(a > b) ? a = ((a - 2) / k) + 1 : b = ((b - 2) / k) + 1;
				cnt++;
			}
//		}
		cout << cnt << '\n'; // endl이 느려서 오류나는거였음 ;ㅅ;

	}
	return 0;
}