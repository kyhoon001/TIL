#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>

#define arr_size 32

using namespace std;
int arr[arr_size];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for(int i = 0; i < lost.size(); i++) {
        arr[lost[i]]--;
    }
    
    for(int i = 0; i < reserve.size(); i++) {
        arr[reserve[i]]++;
    }
    
    for(int i = 1; i <= n; i++) {
        arr[i] += 1;
        if(arr[i] != 0) answer++;
    }
    
    for(int i = 1; i< n; i++) {
        if(arr[i] != 0) continue;
        if(arr[i-1] == 2) {
            arr[i-1]--;
            answer++;
        }else if(arr[i+1] == 2) {
            arr[i+1]--;
            answer++;
        }
    }
    
    
    cout << answer << endl;
    return answer;
}