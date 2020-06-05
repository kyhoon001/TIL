#include <vector>
#include <queue>
#include <algorithm>
using namespace std;




// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int n, int m, vector<vector<int>> picture) {
    
    vector<vector<int>> v;
    v.resize(n);
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(picture[i][j] == 0)
            {
                v[i].push_back(1);
            }
            else v[i].push_back(0);
        }
    }
    
    int cntt = 0;
    int ans = -1;
    
    
    
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(v[i][j] == 0)
            {
                queue<pair<int,int>> q;
                q.push({i,j});
                v[i][j] = 1; // check 배열

                int nn = picture[i][j];
                int cnt = 1;
                while(!q.empty())
                {
                    int a = q.front().first;
                    int b = q.front().second;
                    q.pop();
                    for(int t = 0; t < 4; t++)
                    {
                        int na = a + dx[t];
                        int nb = b + dy[t];
                        if(na >= 0 && nb >= 0 && na < n && nb < m && v[na][nb] != 1 && picture[na][nb] == nn)
                        {
                            v[na][nb] = 1;
                            cnt++;
                            q.push({na,nb});
                        }
                    }
                }
                ans = max(ans, cnt);

                
                cntt++;
            }
        }
    }
    if(ans == -1 ) ans = 0;
    vector<int> answer(2);
    answer[0] = cntt;
    answer[1] = ans;
    
    
    return answer;
}