#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int,int>> s;
    int time = 0;
    for(int i = 0; i < prices.size(); i++) {
        time += 1;
        while(!s.empty() && prices[s.top().first] > prices[i]) { // 가격이 떨어졌으면
            answer[s.top().first] = time - s.top().second;
            s.pop();
        }
        s.push({i,time});

    }
    while(!s.empty()) {
        answer[s.top().first] = time - s.top().second;
        s.pop();
    }
    return answer;
}