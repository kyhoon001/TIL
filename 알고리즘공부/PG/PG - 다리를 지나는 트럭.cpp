#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int w = 0;
    int t = 0;
    queue<pair<int,int>> q; // 첫번은 무게 두번째는 시간
    while(1) {
        answer += 1;
        
        if(!q.empty() && q.front().second + bridge_length == answer) {
            w -= q.front().first;
            q.pop();
        }
        if( w + truck_weights[t] <=  weight) {
//            cout << w << "   " << truck_weights[t] << endl;
 //           cout << t << "번이" << answer << "시간에 들어옴" << endl;
            q.push({truck_weights[t], answer});
            w += truck_weights[t];

            t += 1;
        }
        
        if(t == truck_weights.size()) {
            while(q.size() != 1) {
                q.pop();
            }
  //          cout << q.front().first << "번이" << q.front().second << "시간에 들어옴" << endl;
            return q.front().second + bridge_length;
        }
    }
    
    
    return answer;
}