#include <string>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;
//내가 짠 코드
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int p1[] = {1,2,3,4,5};
    int p2[] = {2,1,2,3,2,4,2,5};
    int p3[] = {3,3,1,1,2,2,4,4,5,5,};
    int mnum = 0;
    int n[3];
    memset(n,0,sizeof(n));
    
    for(int i = 0; i < answers.size(); i++) {
        if(p1[i%5] == answers[i]) n[0]++;
        if(p2[i%8] == answers[i]) n[1]++;
        if(p3[i%10] == answers[i]) n[2]++;
        
    }
    for(int i = 0; i < 3; i++) {
        mnum = max(mnum,n[i]);
    }
    for(int i = 0; i < 3; i++) {
       if(mnum == n[i]) answer.push_back(i+1);
    }
    
    return answer;
}


//다른사람이 짠 코드
/*
    다 같은데 *max_element라는 함수를 사용한 것이 다름

    
    vector<int> they(3);
    for(int i=0; i<answers.size(); i++) {
        if(answers[i] == one[i%one.size()]) they[0]++;
        if(answers[i] == two[i%two.size()]) they[1]++;
        if(answers[i] == thr[i%thr.size()]) they[2]++;
    }
    int they_max = *max_element(they.begin(),they.end());

*/