#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;

#define N 100000000

int arr[N];
string num;
int check[7];
int answer = 0;
void solve(int cnt,int total) {
    
        if(arr[total] == 0) {
            arr[total] = 1;
            answer++;
        }
    if(cnt == num.size()) {
        return;
    }
    
    for(int i = 0; i < num.size(); i++) {
        if(check[i] == 0) {
            check[i] = 1;
            solve(cnt + 1, (total * 10) + (num[i] - '0'));
            check[i] = 0;
        }
    }
}


int solution(string numbers) {
    num = numbers;
    memset(arr,0,sizeof(arr));
    memset(check,0,sizeof(check));
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2; i < N; i++) {
        if(arr[i] == 1) continue;
        for(int j = i * 2; j < N; j+= i) {
            arr[j] = 1;
        }
    }
        solve(0,0);
    cout << answer << endl;
    
    
    return answer;
}