#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <string.h>
#include <queue>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string> hash;
//    map<string,string>::iterator it = hash.begin();
    queue<pair<int,string>> q;
    for(int i = 0; i < record.size(); i++) {
        string uid = "";
        string name = "";
        string s;
        bool ch = true;
        s = record[i].substr(6, record[i].size()-1);
        
        for(int j = 0; j < s.size(); j++) {
            if(s[0] == ' ' && j == 0) continue;
            if(s[j] != ' ') {
                if(ch) uid+= s[j];
                else name+=s[j];
            }
            else ch = false;
        }
        
        if(record[i][0] == 'E') { // 삽입
            hash[uid] = name;
            q.push({0,uid});
        }
        else if(record[i][0] == 'L') {
            q.push({1,uid});
        }
        else if(record[i][0] == 'C') {
            hash[uid] = name;
        }
    }
        while(!q.empty()) {
            string s = "";
            if(q.front().first == 0) {
                s += (hash[q.front().second] + "님이 들어왔습니다.");
            }
            else {
                s += (hash[q.front().second] + "님이 나갔습니다.");
            }
            answer.push_back(s);
            q.pop();
        }
        
        
    
    
    return answer;
}