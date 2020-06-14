#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include <string>
#include <stdio.h>
using namespace std;


//쉬운 문제지만, 반례찾느라 쌩쇼를 했음 조심하자.


int ch[10];
string target;
int answer;
int sz;
void chk(int t, string stmp)
{

	if(t != 0) answer = min(answer, int(abs(stoi(target) - stoi(stmp)) + stmp.size()));
	if (t >= sz)
	{
		answer = min(answer, int(abs(stoi(target) - stoi(stmp))+stmp.size()));
		

		if (t == sz + 1)
			return;	
		// 출력
	}
	
	for (int i = 0; i < 10; i++)
	{
		if (ch[i] == 1) continue;
		chk(t + 1, stmp + char(i + 48));

	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;

	cin >> target >> n;
	memset(ch, 0, sizeof(ch));
	int i,tmp;
	for (i = 0; i < n; i++)
	{
		cin >> tmp;
		ch[tmp] = 1;
	}

	string t = target;
	sz = t.size();
	answer = abs(stoi(target) - 100);



	chk(0, "");
	cout << answer << endl;

	return 0;
}