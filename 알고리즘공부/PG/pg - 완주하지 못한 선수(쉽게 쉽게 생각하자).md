# pg - 완주하지 못한 선수(쉽게 쉽게 생각하자)

- 어렵게 생각하지 말고 쉽게 쉽게 생각하자

```c++
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    
    for(int i = 0; i < completion.size(); i++) {
        if(completion[i] != participant[i]) {
            return participant[i];
        }
    }
    
    
    answer = participant[participant.size()-1];
    return answer;
}
```

