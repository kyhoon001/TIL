#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int n;
long long nums[13];
int op[4];
long long mininum;
long long maxnum;
bool scheck = true;

long long calc(long long nn, long long sum, int opr) {
	//cout << "cacl연산 nn : " << nn << "   sum" << sum << endl;
	if (opr == 0)
		return sum + nn;
	else if (opr == 1)
		return sum - nn;
	else if (opr == 2)
		return sum * nn;
	else
		return sum / nn;
}



void solve(long long nn, long long sum) {
	int opr;

	if (nn == n) {
		if (scheck == true) {
			mininum = sum;
			maxnum = sum;
			scheck = false;
			return;
		}
		else {
			mininum = min(mininum, sum);
			maxnum = max(maxnum, sum);
//			cout << maxnum << "  " << mininum << endl;
			return;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] >= 1) {
			if (i == 4) {
				if (nums[nn] == 0 || sum == 0)
					continue;
			}
			opr = i;
			long long tmp = calc(nums[nn], sum, opr); //sum하고 nn 을 더하던지 빼든지 나누든지 한다.
//            cout << "계산값 : " << tmp << "    sum값 : " << sum << endl;
			op[i] -= 1;
			solve(nn + 1, tmp);
			op[i] += 1;
		}
	}


}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		memset(nums, 0, 13);
		memset(op, 0, 4);
		scheck = true;

		for (int i = 0; i < 4; i++) {
			cin >> op[i];
		}

		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}


		solve(1, nums[0]);
//		cout << "maxnum : " << maxnum << "    mininum : " << mininum << endl;
		cout << "#" << tc << " " << maxnum - mininum << endl;
	}


	return 0;
}