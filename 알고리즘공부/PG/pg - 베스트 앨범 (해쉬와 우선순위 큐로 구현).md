# pg - 베스트 앨범 (해쉬와 우선순위 큐로 구현)



- 풀기는 풀었음

```c++
#include <string>
#include <vector>
#include <map>
#include<iostream>
#include<queue>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> hash;
    priority_queue<pair<int,pair<int,int>>> q;
    
    for(int i = 0; i < genres.size(); i++) {
        hash[genres[i]] += plays[i];
    }
    
    for(int i = 0; i < plays.size(); i++) {
        q.push({hash[genres[i]],{plays[i], -i}});
    }

    int tmp = -1;
    int cnt = 0;
    while(!q.empty()) {
        if(tmp == q.top().first) {
            if(cnt == 2)
                q.pop();
            else {
                cnt += 1;
                answer.push_back(-q.top().second.second);
                q.pop();
            }
            
        }
        else if(tmp != q.top().first) {
            tmp = q.top().first;
            cnt = 1;
            answer.push_back(-q.top().second.second);
            q.pop();
        }
    }

    
//    cout << hash.size() << endl;
    
    return answer;
}
```

