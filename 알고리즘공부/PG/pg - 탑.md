# pg - 탑



```c++
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer(heights.size());
    
    vector<int> check(heights.size());
    
    for(int i = check.size()-1; i >= 0; i--) {
        for(int j = i - 1; j >= 0; j--) {
            if(heights[j] > heights[i]) {
                if(heights[j] > answer[i])
                    answer[i] = j + 1;
                break;
            }
        }
    }
    
    
    
    return answer;
}
```

