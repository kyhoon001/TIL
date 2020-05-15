#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    priority_queue<pair<double,int>> q;
    // n-1까지 하는구나.
    for(int i = 1; i <= N; i++) {
        int u = 0;
        int f = 0;
        for(int j = 0; j < stages.size(); j++) {
           
            if(stages[j] >= i) {
                if(stages[j] == i) f++;
                u++;
                
            }
        }
        if(f == 0 || u == 0) q.push({0,-i});
        else q.push({(double)f/u, -i});
 //       cout << "도달한 사람 : "<< u << "   실패한 사람 : " << f << "   " << f << "/" << u << endl;
    }
    while(!q.empty()) {
  //      cout << "answer : " << q.top().first << endl;
        answer.push_back(-q.top().second);
        q.pop();
    }
    return answer;
}