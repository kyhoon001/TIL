#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    string answer = "";
    int n = s.length();
    
    if(n % 2 == 1)  answer = s[n/2];
    else  answer = s.substr(n/2-1, 2);
    // substr (n/2-1)부터 2글자를 출력한다는 뜻   
    
    return answer;
}