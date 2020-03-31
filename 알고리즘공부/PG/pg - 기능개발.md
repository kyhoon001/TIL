# pg - 기능개발







```cpp
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i = 0; i < progresses.size(); i++) {
        int n = (100 - progresses[i]) / speeds[i];
        if( speeds[i] * n + progresses[i] < 100) n+=1;

        q.push(n);
    }

    int maxi = q.front();
    q.pop();
    int cnt = 1;
    while(!q.empty()) {
        if(maxi >= q.front()) {
            cnt += 1;
            q.pop();
        }
        else {
            answer.push_back(cnt);
            maxi = q.front();
            q.pop();
            cnt = 1;
        }
    }

            answer.push_back(cnt);


    return answer;
}
// 10
```

