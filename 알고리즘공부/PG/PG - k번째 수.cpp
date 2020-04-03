#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> v;
    
    for(int i = 0; i < commands.size(); i++) {
        for(int j = commands[i][0] - 1; j < commands[i][1]; j++) {
            v.push_back(array[j]);
            
        }
        sort(v.begin(), v.end());
        answer.push_back(v[commands[i][2]-1]);
        v.clear();

    }
    return answer;
}