# 백준 - 9663 N-Queen

- 다른 사람 코드

```c++
#include <iostream>

using namespace std;

int N;
int col[16];
int result = 0;

bool promising(int i)
{
	for (int j = 0; j < i; j++)
	{
		// 새로운 퀸과 기존의 퀸이 같은 행에 있거나 대각선에 있을 경우
		if (col[j] == col[i] || abs(col[i] - col[j]) == (i - j))
			return false;
	}
	return true;
}
void N_Queen(int i)
{
	if (i == N)
		result += 1;
	else
	{
		for (int j = 0; j < N; j++)
		{
			col[i] = j;
			if (promising(i))
				N_Queen(i + 1);
		}
	}
}

int main()
{
		result = 0;
		for (int j = 0; j < 16; j++) {
			col[j] = 0;
		}


		cin >> N;
		N_Queen(0);
		cout << result << endl;



	return 0;
}

```

