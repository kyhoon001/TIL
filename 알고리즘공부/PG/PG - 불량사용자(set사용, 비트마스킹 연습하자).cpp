#include <string>
#include <vector>
#include <set>
#include <string.h>
#include <iostream>
using namespace std;
vector<vector<int>> v(0);
int check[9];
set<string> st;
int bsize;
void dfs(int a) {
    if(a == bsize) {
        string s = "";
        for(int i = 0; i < 9; i++) {
            if(check[i] == 0) s += '0';
            else s+= '1';
        }
        st.insert(s);
    }
    
    for(int i = 0; i < v[a].size(); i++) {
        if(check[v[a][i]] == 0) {
            check[v[a][i]] = 1;
            dfs(a + 1);
            check[v[a][i]] = 0;
        }
    }
}


bool compare(string a, string b) { // b는 제제 아이디 a는 응모자
    if(a.size() != b.size()) return false;
    
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) {
            if(b[i] == '*') continue;
        return false;
        }
    }
    return true;
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    v.resize(sizeof(banned_id));
    bsize = banned_id.size();
//    check.resize(sizeof(user_id));
    
    for(int i = 0; i < banned_id.size(); i++) {
        for(int j = 0; j < user_id.size(); j++) {
            if(compare(user_id[j], banned_id[i]) == true) {
                v[i].push_back(j);
            }
        }
    }
    memset(check,0,sizeof(check));
    
    dfs(0);
    
    answer = st.size();
    return answer;
}