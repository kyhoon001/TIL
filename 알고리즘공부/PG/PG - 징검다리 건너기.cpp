#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int n;
bool find(vector<int>& stones, int k, int a) {
    int cnt = 0;
    for(int i = 0;i < n; i++) {
        if(stones[i] - a <= 0) {
            cnt++;
        }
        else cnt = 0;
        if(cnt >= k) return false; // 못 건넘
    }
    return true; // 건넘
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    n = stones.size();
    int l = 1;
    int r = *max_element(stones.begin(), stones.end());
    
    while(l <= r) {
        int m = (l + r )/2;
        if(find(stones,k,m)) {
            l = m+1;
        }
        else r = m-1;
    }
    answer = l;
    
    return answer;
}