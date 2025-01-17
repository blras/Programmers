#include <string>
#include <vector>
#include <queue>
#include <iostream>;
using namespace std;
vector<string> MAPS;
int X;
int Y;
vector<int> dx{0,1,0,-1};
vector<int> dy{1,0,-1,0};
int Maze(pair<int,int> a,pair<int,int> b)
{
    queue<pair<pair<int,int>,int>> q;
    q.push({a,0});
    int answer = 0;
    vector<int> v (Y,-1);
    vector<vector<int>>memo (X,v);
    while(!q.empty())
    {
        pair<pair<int,int>,int> p = q.front();
        q.pop();
        pair<int,int> pp = p.first;
        int x = pp.first;
        int y = pp.second;
        if(memo[x][y]<0||memo[x][y]>p.second)
            memo[x][y] = p.second;
        else
            continue;
        
        for(int i = 0;i<4;i++)
        {
            int tx = x+dx[i];
            int ty = y+dy[i];
            if(tx>=0&&tx<X&&ty>=0&&ty<Y&&(memo[tx][ty]<0||memo[tx][ty]>p.second+1)&&MAPS[tx][ty]!='X')
            {
                pair<pair<int,int>,int> tp = {{tx,ty},p.second+1};
                q.push(tp);
            }
        }
    }
    answer = memo[b.first][b.second];
    return answer;
}
int solution(vector<string> maps) {
    int answer = 0;
    MAPS = maps;
    X = maps.size();
    Y = maps[0].size();
    pair<int,int> s;
    pair<int,int> e;
    pair<int,int> l;
    for(int i = 0;i<X;i++)
    {
        for(int j = 0;j<Y;j++)
        {
            if(maps[i][j]=='S')
                s = {i,j};
            if(maps[i][j]=='E')
                e = {i,j};
            if(maps[i][j]=='L')
                l = {i,j};
        }
    }
    int a = Maze(s,l);
    int b = Maze(l,e);
    if(a<0||b<0)
        answer = -1;
    else
        answer = a+b;
    return answer;
}