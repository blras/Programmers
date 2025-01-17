#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<bool>> memo;
vector<string>MAPS;
vector<int> dx = {0,1,0,-1};
vector<int> dy = {1,0,-1,0};
int BFS(int a, int b)
{
    queue<pair<int,int>> q;
    q.push({a,b});
    memo[a][b]=true;
    int count = 0;
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        count+=(MAPS[p.first][p.second]-'0');
        for(int i =0;i<4;i++)
        {
            int x = p.first+dx[i];
            int y = p.second+dy[i];
            if(x>=0&&x<MAPS.size()&&y>=0&&y<MAPS[p.first].size())
            {
                if(!memo[x][y]&&MAPS[x][y]!='X')
                {
                    memo[x][y]=true;
                    q.push({x,y});
                }
            }
        }
    }
    return count;
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<bool> b (maps[0].size(),false);
    memo = vector<vector<bool>> (maps.size(),b);
    MAPS = maps;
    for(int i = 0;i<maps.size();i++)
    {
        for(int j = 0;j<maps[i].size();j++)
        {
            if(maps[i][j]!='X'&&!memo[i][j])
            {
                answer.push_back(BFS(i,j));
            }
        }
    }
    if(answer.size()==0)
        answer.push_back(-1);
    else
        sort(answer.begin(),answer.end());
    return answer;
}