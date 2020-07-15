#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
using namespace std;

int arr[10001], check[10001];
int n, num1, num2;
string s1, s2;

int to_int(string s)
{
	int tmp = 0;
	tmp += (s[0] - '0') * 1000;
	tmp += (s[1] - '0') * 100;
	tmp += (s[2] - '0') * 10;
	tmp += (s[3] - '0');

	return tmp;
}

void bfs(string start)
{
	queue<string> q;
	q.push(start);
	check[to_int(start)] = 0;
	while (!q.empty()) {
//		cout << endl << endl << endl << endl;
		string st = q.front();
		string s = st;
//		cout << st << "에서 갈 수 있는것 !!!!!" << endl;
		q.pop();

		for (int i = 0; i < 4; i++) {
			s = st;
			for (int j = 0; j < 10; j++) {
				if (i == 0 && j == 0) continue;

//				if (j == (start[i] - '0')) continue;

				s[i] = (j + '0');
				if (arr[to_int(s)] == 0 && check[to_int(s)] == -1) { // 소수이면
					q.push(s);
					check[to_int(s)] = check[to_int(st)] + 1;
//					cout << s << "넣음" << endl;
//					cout << "거리 : " << check[to_int(s)] << endl;
				}
			}
		}
	}
}



int main()
{
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < 10000; i++) {
		int tmp = i + i;
		while (tmp < 10000) {
			if (arr[tmp] != 1) {
				arr[tmp] = 1;
			}
			tmp += i;
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num1 >> num2;
		s1 = to_string(num1);
		s2 = to_string(num2);
		//cout << "애초에 결과가 소수가 맞음?" << arr[num2] << endl;
		memset(check, -1, sizeof(check));
		bfs(s1);

		if (check[to_int(s2)] == -1) cout << "Impossible" << endl;
		else cout <<  check[to_int(s2)] << endl;


		/*

		cout << check[to_int(s1)] << endl;
		cout << 1733 << "  : " << arr[1733] << endl;
		cout << 3733 << "  : " << arr[3733] << endl;
		cout << 3739 << "  : " << arr[3739] << endl;
		cout << 3779 << "  : " << arr[3779] << endl;
		cout << 8779 << "  : " << arr[8779] << endl;
		cout << 8179 << "  : " << arr[8179] << endl;
		*/
	}

	


	return 0;
}