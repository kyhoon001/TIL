# pg - 위장 해쉬, 맵 사용법

- map 어떻게 사용하는지 문법 잘 보기

```c++
#include <string>
#include <vector>
#include<iostream>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> hash;
    //모자의 개수 * 상의 개수 * 하의 개수 ..... 겉옷 개수 이런식으로 곱해줌.
    //각 물품들을 안 썼을 때의 경우도 있으므로 각 물품의 개수는 = 물품의 개수 + 1(안 썼을 때)가 됨
    // 다 벗었을 경우는 없으므로 위에서 계산한 결과에서 -1을 해주어야함.
    
    
//    cout << clothes[0][1] << endl;  // clothes[0][1] 에 물품의 종류가 들어있음.
    for(int i = 0; i < clothes.size(); i++) {
        hash[clothes[i][1]] += 1; // clothes[i][1] 은 옷 종류
        // 옷 종류를 index로 사용하여 해당 값을 1 올려줌
    }
    map<string,int>::iterator iter;
    
    for(iter = hash.begin(); iter != hash.end(); iter ++) {
        answer *= (iter->second + 1); // iter는 hash를 가리키고 있음
        //그러므로 iter->second는 hash에서 두번째 즉 int형 데이터를 의미함.
    }
    answer -= 1; 
    return answer;
}
```

