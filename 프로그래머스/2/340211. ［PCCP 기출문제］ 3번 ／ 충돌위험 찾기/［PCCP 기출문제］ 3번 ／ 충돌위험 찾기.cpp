#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    int psize = points.size();
    int rsize = routes.size();
    vector<vector<pair<int,int>>> v;
    for(int i = 0;i<rsize;i++)
    {
        pair<int,int> temp ={points[routes[i][0]-1][0],points[routes[i][0]-1][1]};
        v.push_back({temp});
    }
    for(int i = 0;i<rsize;i++)
    {
        int x = points[routes[i][0]-1][0];
        int y = points[routes[i][0]-1][1];
        for(int j = 1;j<routes[i].size();j++)
        {
            int gx = points[routes[i][j]-1][0];
            int gy = points[routes[i][j]-1][1];
            while(x!=gx||y!=gy)
            {
                if(x!=gx)
                {
                    if(x>gx)
                        x--;
                    else
                        x++;
                }
                else if(y!=gy)
                {
                    if(y>gy)
                        y--;
                    else
                        y++;
                }
                pair<int,int> temp = {x,y};
                v[i].push_back(temp);
            }
        }
    }
    int t = 0;
    for(int i = 0;i<v.size();i++)
    {
        if(v[i].size()>t)
            t = v[i].size();
    }
    for(int i = 0;i<t;i++)
    {
        set<pair<int,int>> s;
        set<pair<int,int>> cs;
        int ss = 0;
        int css = 0;
        for(int j = 0;j<v.size();j++)
        {
            if(v[j].size()>i)
            {
                s.insert(v[j][i]);
                if(s.size()==ss)
                {
                    cs.insert(v[j][i]);
                    if(cs.size()>css)
                    {
                        answer++;
                        css = cs.size();
                    }
                    
                }
                else
                    ss = s.size();
            }
        }
    }
    return answer;
}