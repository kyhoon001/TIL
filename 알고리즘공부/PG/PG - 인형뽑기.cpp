#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    for(int i = 0; i < moves.size(); i++) {
        int n = moves[i] - 1;
        for(int j = 0; j < board[0].size(); j++) {
            if(board[j][n] != 0) {
                if(!s.empty()) {
                    if(s.top() == board[j][n]) {
                        answer += 2;
                        s.pop();
                        board[j][n] = 0;
                        break;
                    }
                }
            s.push(board[j][n]);
            board[j][n] = 0;
            break;
            }

        }
    }
    
    
    return answer;
}