#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
    long long answer = 0;
    long long t = 10000000000;
    cout << t << endl;
    long long n = budgets.size();
    int r = 0;
    int l = M;
    
    for(int i = 0; i < n; i++) {
        answer += budgets[i];
        l = min(budgets[i],l);
        r = max(budgets[i],r);
    }
    if(answer > M) {
        answer = 0;
        if(l * n > M) l = 0;
    while(r >= l) {
        long long mid = (r + l) / 2;
        long long tmp = 0;
        //cout << "mid : " << mid << endl;
        for(int i = 0; i < n; i++) {
            if(budgets[i] > mid) tmp+= mid;
            else tmp += budgets[i];
        }
        if(M < tmp) {
            r = mid - 1;
            //cout << "더 작아져야함 max : : " << r << endl;
        }
        else {
            l = mid + 1;
            //cout << "커져야함 : " << l << endl;
        }
    }
    }
    answer = r;
    //cout << answer << endl;
    return answer;
}