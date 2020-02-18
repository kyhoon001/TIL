# s/w 문제해결 응용 3일차 - 최적경로

```c++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
 
using namespace std;
int n;
int answer;
 
typedef struct {
    int a; int b;
}loc;
 
loc arr[13];
bool check[11];
loc wp;
loc home;
 
 
void solve(int start, int cnt, int total) {
 
    if (total > answer) {
        return;
    }
 
    if (cnt == n) {
        total += abs(arr[start].a - home.a) + abs(arr[start].b - home.b);
 
        if (total < answer) {
            answer = total;
        }
            return;
    }
 
 
    for (int i = 0; i < n; i++) {
        if (check[i] == false) { // 아직 탐색이 안 됐다면
            check[i] = true;
            if (start == -1) {
                solve(i, cnt + 1, total + abs(wp.a - arr[i].a) + abs(wp.b - arr[i].b));
            }
            else
                solve(i, cnt + 1, total + abs(arr[start].a - arr[i].a) + abs(arr[start].b - arr[i].b));
            check[i] = false;
 
        }
 
 
    }
 
 
}
 
 
 
 
 
int main() {
//      freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int tc;
    cin >> tc;
    for (int q = 1; q <= tc; q++) {
        cin >> n;
 
        answer = 99999;
        memset(check, false, 11);
        cin >> wp.a >> wp.b >> home.a >> home.b;
        for (int i = 0; i < n; i++) {
            cin >> arr[i].a >> arr[i].b;  
        }
 
 
        solve(-1, 0, 0);
 
        cout << "#" << q << " " << answer << endl;
    }
    return 0;
}
```

