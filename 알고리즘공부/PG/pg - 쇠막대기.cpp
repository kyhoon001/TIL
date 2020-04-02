#include <string>
#include <vector>
#include<stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> s;
    
    s.push(arrangement[0]);
    for(int i = 1; i < arrangement.size(); i++) {
        if(arrangement[i] == ')') {
            if(arrangement[i-1] != '(') {
                s.pop();
            }
            else if(arrangement[i-1] == '(') {
                s.pop();
                answer += s.size();
            }
        }
        else if(arrangement[i] == '(') {
            s.push(arrangement[i]);
            if(arrangement[i-1] == '(') answer += 1;
        }
    }
    
    
    
    return answer;
}