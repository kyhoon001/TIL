# s/w 문제해결 응용 3일차 - 최적 경로

```c++
#include <iostream>
#include<algorithm>
 
using namespace std;
 
 
typedef struct {
    int a, b;
} Dir;
 
int n;
int q = 1;
Dir cu[11];
bool check[11];
Dir home;
Dir des;
int answer;
 
 
void solve(int la, int lb, int sum, int cnt) {
 
    if (answer < sum) {
        return;
    }
    else if (n <= cnt) { // 탐색끝나면
        sum += (abs(home.a - la) + abs(home.b - lb));
//      cout << "answer : " << answer << "   and sum : " << sum << endl;
        answer = min(sum, answer);
 
        return;
    }
 
        for (int i = 0; i < n; i++) {
            if(!check[i]) {
                check[i] = true;
                solve(cu[i].a, cu[i].b, sum + (abs(cu[i].a - la) + abs(cu[i].b - lb)), cnt+1);
                check[i] = false;
            }
        }
     
 
 
 
 
}
 
 
 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tra;
    cin >> tra;
 
    for (; q <= 10; q++) {
        int a, b;
 
        cin >> n;
        cin >> a >> b;
        des.a = a;
        des.b = b;
 
 
        cin >> a >> b;
        home.a = a;
        home.b = b;
 
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            cu[i].a = a;
            cu[i].b = b;
            check[i] = false;
        }
 
        answer = 9999999999;
        solve(des.a, des.b, 0, 0);
 
 
        cout << "#" << q << " " << answer << endl;
 
    }
        return 0;
 
}
```

