#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int arr[200000];
    vector<pair<int,string>> v;
    string stmp;
    int cnt = 1;
    memset(arr,0,sizeof(arr));
    for(int i = 1; i < s.size()-1; i++) {
        if(s[i] == '{') {
            stmp = "";
        }
        else if(s[i] == '}') {
            v.push_back({cnt,stmp});
            cnt = 1;

        }
        else {
            if(s[i] == ',' && stmp != "") cnt+=1;
            stmp = stmp + s[i];
        }
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < v.size(); i++) {
        stmp= "";
        for(int j = 0; j < v[i].second.size(); j++) {
            if(v[i].second[j] == ',') {
                if(arr[stoi(stmp)] == 0) {
                    arr[stoi(stmp)] = 1;
                    answer.push_back(stoi(stmp));
                }
                stmp="";
            }
            else stmp += v[i].second[j];
        }
        if(arr[stoi(stmp)] == 0) {
            arr[stoi(stmp)] = 1;
            answer.push_back(stoi(stmp));
        }
        
    }
    
    
    return answer;
}