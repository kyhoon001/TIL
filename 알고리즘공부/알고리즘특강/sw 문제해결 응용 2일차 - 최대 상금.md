# s/w 문제해결 응용 2일차 - 최대 상금

```c++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
 
using namespace std;
char tmp;
int maxi = -1;
int itmp;
int semi;
bool st = false;
int check[7];
string smax = "";
 
 
void solve(string s, int cnt) {
    if (smax == s) {
        st = true;
        int ttmp = itmp;
        semi = 0;
        int arr[10] = { 0 };
        for (int i = 0; i < s.length(); i++) {
            if (arr[s[i] - '0'] == 1) {
                for (int i = 0; i < s.length(); i++) {
                    semi += (s[i] - '0') * ttmp;
                    ttmp /= 10;
                }
                maxi = semi;
                return;
            }
            arr[s[i] - '0']++;
        }
 
 
        if (cnt % 2 == 1) {
//              cout << "바꿈?" << endl;
                int b;
                b = s[s.length() - 1];
                s[s.length()-1] = s[s.length() - 2];
                s[s.length()-2] = b;
        }
 
 
        for (int i = 0; i < s.length(); i++) {
            semi += (s[i] - '0') * ttmp;
            ttmp /= 10;
        }
 
 
        if (semi > maxi) {
            maxi = semi;
        }
        return;
    }
 
 
    if (cnt == 0) {
        int ttmp = itmp;
        semi = 0;
        for (int i = 0; i < s.length(); i++) {
            semi += (s[i] - '0') * ttmp;
            ttmp /= 10;
        }
        if (semi > maxi) {
            maxi = semi;
        }
        return;
    }
 
 
 
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < s.length(); j++) {
            if (i == j) {
                continue;
            }
//          cout << i << "하고  " << j << "하고 바꿈" << endl;
//          cout << s[i] << "          " << s[j] << endl;
            int tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
//          cout << s << endl;
            solve(s, cnt - 1);
            if (st == true)
                return;
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
 
        }
    }
 
}
bool desc(int a, int b) { return a > b; }
 
 
 
int main() {
//      freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    string s;
    int n;
    int tc;
    cin >> tc;
    for (int q = 1; q <= tc; q++) {
        cin >> s >> n;
        itmp = 1;
        maxi = -1;
        smax = "";
        st = false;
        memset(check, -1, 7);
        for (int i = 1; i < s.length(); i++) {
            itmp *= 10;
        }
 
        for (int i = 0; i < s.length(); i++) {
            check[i] = s[i];
        }
        sort(check, check + s.length(),desc); //  내림차순.
         
         
 
        for (int i = 0; i < s.length(); i++) {
            smax += check[i];
        }
 
 
        solve(s, n);
 
 
        cout << "#" << q << " " << maxi << endl;
    }
    return 0;
}
```

