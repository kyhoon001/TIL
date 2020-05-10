#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i = 0; i < skill_trees.size(); i++) {
        int a = 0;
        bool can = true;
//        cout << skill_trees[i] << "  : ";
        for(int j = 0; j < skill_trees[i].size();j++) {
            if(skill_trees[i][j] == skill[a]) {
  //              cout << skill_trees[i][j] << "   " << skill[a] << endl;
                a++;
                
                continue;
            }
            else {
                for(int k = a+1; k < skill.size(); k++) {
//                    cout << skill_trees[i]<<  "   ," << j  << "  :";
 //                   cout << "첨 틀림 : " << skill_trees[i][j] << "  " << skill[a] << endl;
                    if(skill_trees[i][j] == skill[k]) {
                        can = false;
//                        cout << "false" << endl;
                        break;
                    }
                }
            }
            if(can == false) break;
        }
        if(can == true) answer++;
    }
    
    return answer;
}