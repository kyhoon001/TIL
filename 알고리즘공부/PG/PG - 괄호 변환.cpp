#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;
int n;
int good(string s) //짝이 다 맞는가를 식별
{
    if(s == "") return -1;
    stack<int> st;
    if(s[0] == ')') return 0;
    st.push(s[0]);
    int tmp;
    for(int i = 1; i< s.size(); i++) {
        if(st.size() == 0 && s[i] == ')') {
            
            return i; //i번째에서 틀림. i번째 전까지는 짝이 맞음
        }
        if (s[i] == '(') {
            if(st.size() ==0) tmp = i;
            st.push('(');
        }
        else if(st.top() == '(' && s[i] == ')') st.pop();
        
    }
    
    if(st.size() == 0) return -1; // 다 맞다는 뜻
    else return tmp;
}

int balance(string s) {
    int l = 0;
    int r = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') l++;
        else r++;
        if(l != 0 && l == r) return i;
    }
    
    return 0;
}

string solve(string p) {
    if(good(p) == -1) {
        return p;
    }
    int idx;
    int start = 0;
    int end = p.size();
    string answer = "";
    idx = balance(p);
    string u = p.substr(start, idx-start+1);
    start = idx + 1;
    string v = p.substr(start, p.size()-start );
    
    if(good(u) == -1) { //3. 올바른 괄호 문자열일 경우
        answer = u + solve(v);
        //u += solve(v);
    }else { // 4
        answer += '(';
        answer += solve(v);
        answer += ')';
        u = u.substr(1,u.size()-2);
        for(int i = 0; i < u.size(); i++) {
            if(u[i] == ')') u[i] = '(';
            else u[i] = ')';
        }
        answer += u;
    }
    return answer;
}

string solution(string p) {
    string answer = "";
    if(p.size() == 0) return answer;
    if(good(p) == -1) {
        answer = p;
        return answer;
    }
    answer = solve(p);
    //cout << answer << endl;
    
    return answer;
}