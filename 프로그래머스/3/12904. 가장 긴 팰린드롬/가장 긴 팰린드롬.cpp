#include <iostream>
#include <string>
#include <queue>
using namespace std;
int solution(string s)
{
    int answer=1;
    int size = s.size();
    vector<bool> tb (size,false);
    vector<vector<bool>> visit(size,tb); 
    queue<pair<int,int>> q;
    q.push({0,size-1});
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        if(visit[x][y])
            continue;
        visit[x][y] =true;
        bool isPal = true;
        for(int i = 0;x+i<y-i;i++)
        {
            if(s[x+i]!=s[y-i])
            {
                if(x+1<y&&!visit[x+1][y])
                    q.push({x+1,y});
                if(x<y-1&&!visit[x][y-1])
                    q.push({x,y-1});
                isPal = false;
                break;
            }
        }
        if(isPal)
            return y-x+1;
    }
    return answer;
}