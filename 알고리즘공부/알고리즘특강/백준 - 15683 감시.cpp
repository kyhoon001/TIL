#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int arr[9][9],n,m;
int check[9][9];
vector<pair<int, int>> v;
int answer = 0;
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
//이번 문제도 조건을 잘 못 읽어서 30분을 쓸데없이 헤맸다.
//문제를 꼼꼼히 읽고 정리하고 풀이하는 습관을 들이자.
////////////////////////////////////////////////////////

void up(int a, int b)
{
	for (int i = a - 1; i >= 0; i--)
	{
		if (arr[i][b] == 6) // 만약 벽이거나 이미 감시중이면
		{
			return;
		}
		else check[i][b] = 1;
	}

}
void down(int a, int b)
{
	for (int i = a + 1; i < n; i++)
	{
		if (arr[i][b] == 6) // 만약 벽이거나 이미 감시중이면
		{
			return;
		}
		else check[i][b] = 1;
	}

}
void right(int a, int b)
{
	for (int i = b + 1; i < m; i++)
	{
		if (arr[a][i] == 6) // 만약 벽이거나 이미 감시중이면
		{
			return;
		}
		else check[a][i] = 1;
	}
}
void left(int a, int b)
{
	for (int i = b - 1; i >= 0; i--)
	{
		if (arr[a][i] == 6) // 만약 벽이거나 이미 감시중이면
		{
			return;
		}
		else check[a][i] = 1;
	}
}

void ch(int a, int b, int c)
{
	if (arr[a][b] == 1)
	{
		if (c == 0) up(a, b);
		else if (c == 1) right(a, b);
		else if (c == 2) down(a, b);
		else if (c == 3) left(a, b);
	}
	else if (arr[a][b] == 2)
	{
		if (c == 0 || c == 2)
		{
			up(a, b);
			down(a, b);
		}
		else if (c == 1 || c == 3) {
			right(a, b);
			left(a, b);
		}
	}
	else if (arr[a][b] == 3)
	{
		if (c == 0)
		{
			up(a, b);
			right(a, b);
		}
		else if (c == 1) {
			right(a, b);
			down(a, b);
		}
		else if (c == 2) {
			left(a, b);
			down(a, b);
		}
		else if (c == 3) {
			up(a, b);
			left(a, b);
		}
	}

	else if (arr[a][b] == 4)
	{
		if (c == 0)
		{
			up(a, b);
			right(a, b);
			left(a, b);
		}
		else if (c == 1) {
			right(a, b);
			down(a, b);
			up(a, b);
		}
		else if (c == 2) {
			left(a, b);
			down(a, b);
			right(a, b);
		}
		else if (c == 3) {
			up(a, b);
			left(a, b);
			down(a, b);
		}
	}
	else if(arr[a][b] == 5)
	{
		up(a, b);
		down(a, b);
		left(a, b);
		right(a, b);
	}

}
void cpy(int arr2[][9])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr2[i][j] = check[i][j];
		}
	}
}

void back(int arr2[][9])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			check[i][j] = arr2[i][j];
		}
	}
}

void solve(int a)
{
	//0 = 위 1 = 오른 2 = 아래 3 = 왼
	if (a == v.size())
	{
		int tmp = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (check[i][j] == 1)
				{
					tmp++;
				}
			}
		}
		answer = max(answer, tmp);


		return;
	}
	int arr2[9][9];
	cpy(arr2);
	for (int i = 0; i < 4; i++)
	{
		ch(v[a].first, v[a].second, i);
		solve(a + 1);
		back(arr2);
	}

}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	memset(check, 0, sizeof(check));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 6) check[i][j] = 1;
			if (arr[i][j] != 0 && arr[i][j] != 6)
			{
				check[i][j] = 1;
				v.push_back({ i,j });
			}
		}
	}
	answer = 0;
	solve(0);
	cout << n * m - answer << endl;

	return 0;
}