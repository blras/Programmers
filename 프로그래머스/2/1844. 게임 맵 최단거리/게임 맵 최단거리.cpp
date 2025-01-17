#include<vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int n = maps.size();
    int m = maps[0].size();
    queue<pair<int,int>> q;
    pair<int,int> p = {0,0};
    q.push(p);
    vector<int> v (m,-1);
    vector<vector<int>> length (n,v);
    length[0][0] = 1;
    vector<int> dx {1,0,-1,0};
    vector<int> dy {0,1,0,-1};
    while(!q.empty())
    {
        pair<int,int> spot = q.front();
        q.pop();
        int temp = length[spot.first][spot.second];
        for(int i =0;i<4;i++)
        {
            int x = spot.second+dx[i];
            int y = spot.first+dy[i];
            if(x>=0&&x<maps[0].size()&&y>=0&&y<maps.size())
            {
                if(maps[y][x]==1&&(length[y][x]==-1||length[y][x]>temp+1))
                {
                    length[y][x] = temp+1;
                    pair<int,int> ptemp={ y,x} ;
                    q.push(ptemp);
                }
            }
        }
    }
    answer = length[n-1][m-1];
    return answer;
}