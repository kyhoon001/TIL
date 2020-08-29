#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <map>
using namespace std;
int n, m, tmp;
int arr[101];
int check[101];
int check2[101];
int answer = 0;

bool last(int a) { // 해당 숫자가 꽂혀있음녀 true 아니면 false
	
	for (int i = 0; i < n; i++) {
		if (check[i] == 0) {
			check[i] = a;
			return true;
		}
		if (a == check[i]) return true;
	}
	return false;
}

void pull(int a) { // 꽂아야되는 순서
	memset(check2, 0, sizeof(check2));
	for (int i = a; i < m; i++) {
		int cnt = 0;
		tmp = 0; // 어느 콘센트가 빠져야하는지 저장
		for (int j = 0; j < n; j++) {
			if (check[j] == arr[i]) { // 이미 꽂혀있는 것이 나오면
				check2[j] += 1;
			}
			if (check2[j] == 0) {
				cnt++;
				tmp = j;
			}
		}
		if (cnt == 1) {
			answer++;
			check[tmp] = arr[a];
			//cout << arr[tmp] << "번 뽑고 " << arr[a] << "를 꽂음." << endl;
			return;
		}
	}
	check[tmp] = arr[a];
	answer++;
	//cout << arr[tmp] << "번 뽑고 " << arr[a] << "를 꽂음." << endl;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;


	int tmp = 0;
	int cnt = 0;
	for (int i = 0; i < m; i++) {

		cin >> arr[i];
		/*
		if (last(arr[i]) == false) { // 콘센트에서 뽑아야하는 상황이면
			cout << arr[i] << "는 안 꼽혀있음" << endl;
			pull(i);
		}
		*/
	}

	for (int i = 0; i < m; i++) {
		if (last(arr[i]) == false) { // 콘센트에서 뽑아야하는 상황이면
			//cout << arr[i] << "는 안 꼽혀있음" << endl;
			pull(i);
		}

	}
	cout << answer << endl;
	return 0;
}