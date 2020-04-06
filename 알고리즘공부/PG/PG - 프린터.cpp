#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q;
    priority_queue<int> pq;
    
    for(int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
        pq.push(priorities[i]);    
    }
    
    while(1) {
        if(pq.top() != q.front().first) {
            q.push({q.front().first, q.front().second});
            q.pop();
            
        }
        else if(pq.top() == q.front().first)  {//나올 차례
               answer += 1;
            if(q.front().second == location) {
                return answer;
            }
            else {
                q.pop();
                pq.pop();
            }
            
        }
    }
    
    return answer;
}