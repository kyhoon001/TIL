#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int cntresult(string s, string s2)
{
    if(s2.size() > s.size()) {
        return -1;
    }
    int cnt = 1;
    int idx = 0;
    for(int i = 0; i < s.size(); i++) {
        //if(i + s2.size() >= s.size()) break;
        if(s[i] == s2[idx]) {
            idx++;
            if(idx == s2.size()) {
                idx = 0;
                cnt++;
            }
        }else break;
    }
    return cnt;
}

int solution(string s) {
    int answer = 0;
    answer = s.size();
    int n = s.size()/2;
    for(int i = 1; i <= n; i++) {
        string s2 ="";
        for(int j = 0; j < s.size(); ) {
            string ss = s.substr(j,i);
            int cnt = cntresult(s.substr(i+j,s.size()-(i+j)), ss);
            if(cnt >= 2) {
                s2 += to_string(cnt) + ss;
                j = j+(ss.size())* (cnt);
            }else if(cnt == -1) {
                //cout << "끝" << endl;
                s2 +=ss + s.substr(i+j,s.size()-(i+j));
                break;
            }else {
                s2 += ss;
                j += ss.size();
            }
            if( i + j > s.size()) {
                s2 += s.substr(j, s.size()-j);
                break; // 범위 넘어가면 break하게함.
            }
           // cout << i <<"개씩 자르면" << cnt << ss << s.substr(i+j,s.size()-i-j) << endl;
            //cout << "현재 s2 : " << s2 << endl;
        }
        if(answer > s2.size()) {
            answer = s2.size();
            //cout << s2 << endl;   
        }
        //answer = min(answer, s2.size());
    }
    return answer;
}