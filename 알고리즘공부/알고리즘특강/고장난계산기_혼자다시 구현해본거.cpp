#include <iostream>
#include <cmath>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;

int tc, n;
bool num[10];
int answer;

int solve(int number) {
	int snum = (int)sqrt(number);
	int returns = -1;
	int tmp1, tmp2, ctmp;

	for (int i = 2; i <= snum; i++) {
		if (number % i == 0) {
			tmp1 = solve(number / i);
			tmp2 = solve(i);
		if (tmp1 != -1 && tmp2 != -1) {
			ctmp = tmp1 + tmp2 + 1;
			if (returns == -1 || ctmp < returns) {
				returns = ctmp;
			}
		}

		}

	}

	ctmp = 0;
	while (number) {
		if (num[number % 10] == false) { // 1의 자리가 음 계산기로 누를 수 없으면.
			break;
		}
		ctmp += 1;
		number /= 10;
	}

	if (number == 0) { // 다 나눠서 0임. 즉 계산이 끝났으면.
		if (returns == -1 || returns > ctmp) {

			returns = ctmp;
		}
	}



	return returns;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		memset(num, false, sizeof(num));
		int a;
		for (int i = 0; i < 10; i++) {
			cin >> a;
			if (a == 1) {
				num[i] = true;
			}
		}
		cin >> n;
		

		answer = solve(n);
		if (answer != -1) {
			answer += 1;
		}




		cout << '#' << t << ' ' << answer << endl;
	}
}