# s/w 문제해결 기본 3일차 - String

```c++
#include<iostream>
#include<string>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int t = 1; t <= 10; t++) {
		int n;
		cin >> n;
		string s1, s2;  //s1이 찾을 문자 s2는 문자더미
		cin >> s1 >> s2;
		int cnt = 0;
		bool check = false;
		for (int i = 0; i < s2.length(); i++) {
			if (s2[i] == s1[0]) {
				for (int j = 0; j < s1.length(); j++) {
					if (s2[i + j] != s1[j]) {
						i += j;
						check = false;
						break;
					}
					check = true;
				}
				if (check == true) {
					cnt++;
					check = false;
				}
			}
		}
		cout << "#" << n << " " << cnt << endl;









	}
	
	return 0;
}
```

