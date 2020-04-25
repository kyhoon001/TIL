#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    sort(s.begin(),s.end(),greater<char>());
    answer = s;
    return answer;
}


/* 파이썬의 경우
sorted의 경우 sort와 달리 원본에는 영향을 끼치지 않음.

def solution(s):
    return ''.join(sorted(s, reverse=True))



*/