#include <string>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int solution(vector<int> scoville, int k) {
    int answer = 0;    
    priority_queue<int, vector<int>, greater<int>> q;


    
    for(int i = 0; i < scoville.size(); i++) {
        
        q.push(scoville[i]);
    }
    
    while(!q.empty()) {
        if(q.top() >= k) return answer;
        if(q.size() < 2) return -1;
        else if(q.top() < k && q.size() > 1) {
            int n1 = q.top();
            q.pop();
            int n2 = q.top();
            q.pop();
            q.push(n1 + (n2 * 2));
            answer += 1;

        }
    }
    
    
    
    return answer;
}