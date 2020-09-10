#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <map>
#include <queue>
using namespace std;
int n;

string s[101];
int check[101];
int arr[101][101];
priority_queue < pair<int, pair<int, int>>> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(s[i][j] >= 'a' && s[i][j] <= 'z') arr[i][j] = s[i][j] - 'a' + 1;
			else if (s[i][j] == '0') arr[i][j] = 0;
			else arr[i][j] = s[i][j] - 'A' + 27;
			check[i] = i;
			//cout << arr[i][j] << " ";
			if(i != j && arr[i][j] != 0) q.push({ -arr[i][j],{i,j} });
		}
		//cout << endl;
	}
	while (!q.empty()) {
		int a = q.top().second.first;
		int b = q.top().second.second;
		int c = -q.top().first;
		q.pop();
		if (check[a] == check[b]) continue; // 연결이 되어있다는 뜻
		//cout << a << "랑 " << b << "가 연결되어있음 값 : " << c << endl;
		int tmp = check[max(a, b)];
		check[max(a, b)] = check[min(a,b)];
		
		if (arr[a][b] < arr[b][a]) {
			if(arr[a][b] != 0) arr[a][b] = 0;
			else arr[b][a] = 0;
		}
		else {
			if (arr[b][a] != 0) arr[b][a] = 0;
			else arr[a][b] = 0;
		}
		for (int i = 0; i < n; i++) {
			if (check[i] == tmp) check[i] = check[a];
		}

		
	}
	int sum = 0;
	int tmp = check[0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += arr[i][j];
			if (check[i] != tmp) {
				cout << -1 << endl;
				return 0;
			}
			//cout << arr[i][j] << " ";
		}
		//cout << endl;
	}
	
	/*
	cout << endl << endl << endl;
	for (int i = 0; i < n; i++) {
		cout << check[i] << " ";
	}
	*/
	cout << sum << endl;
	return 0;
}