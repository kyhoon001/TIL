# pg - 전화번호 목록(substr을 사용)

- substr을 익숙하게 사용하자
- 경우에 따라 hash보다 더 효율적

```c++
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0; i < phone_book.size() - 1; i++) {
        for(int j = i+1; j < phone_book.size()-1; j++) {
            if(phone_book[i].size() > phone_book[j].size()) continue;
            if(phone_book[i] == phone_book[j].substr(0,phone_book[i].size())) {
                return false;
            }
        }
    }
    
    
    
    return true;
}
```



