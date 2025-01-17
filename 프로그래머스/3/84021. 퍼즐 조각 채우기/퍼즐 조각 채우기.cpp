#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<vector<vector<int>>> GetBlock(vector<vector<vector<int>>> v,int x, int y, int on)
{
    int off = 0;
    if (on == 0)
        off = 1;
    vector<int> row (11,0); 
    vector<vector<int>> blocks (11,row);
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};
    
    queue<vector<int>> q;
    vector<int> xy = {x,y};
    blocks[5][5]=1;
    q.push(xy);
    while(!q.empty())
    {
        vector<int> qv = q.front();
        v[0][qv[0]][qv[1]] = off;
        q.pop();
        for(int i = 0; i<4;i++)
        {
            int tempx = qv[0]+dx[i];
            int tempy = qv[1]+dy[i];
            if(tempx>=0&&tempx<v[0].size()&&tempy>=0&&tempy<v[0].size())
            {
                if(v[0][tempx][tempy]==on)
                {
                    vector<int> tempv = {tempx,tempy};
                    blocks[tempx-x+5][tempy-y+5] = 1;
                    q.push(tempv);
                }
            }
        }
    }
    v.push_back(blocks);
    return v;
}
vector<vector<int>> Rotate(vector<vector<int>> v)
{
    vector<vector<int>> table = v;
    vector<vector<int>> able = v;
    int size = table.size();
    int gx = -1;
    int gy = -1;
    for(int i = 0;i<size;i++)
    {
        for(int j = 0; j<size;j++)
        {
            table[i][j] = v[size-1-j][i];
        }
    }
    return table;
}
int Fill(vector<vector<int>> v,vector<vector<int>> b)
{
    int size = v.size();
    int count = 0;
    int gx=-1;
    int gy=-1;
    for(int i = 0;i<size;i++)
    {
        for(int j = 0;j<size;j++)
        {
            if(b[i][j]==1)
            {
                gx = i;
                gy = j;
                break; 
            }  
        }
        if(gx>=0)
            break;
    }
    for(int i = 0;i<size;i++)
    {
        for(int j = 0;j<size;j++)
        {
            if(i-gx+5>=0&&i-gx+5<size&&j-gy+5>=0&&j-gy+5<size)
            {   
                if(v[i-gx+5][j-gy+5]!=b[i][j])
                    return 0;
                else if (v[i-gx+5][j-gy+5]==b[i][j]&&v[i-gx+5][j-gy+5]==1)
                {
                    count++;
                }
            }
        }
    }
    return count;
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    vector<vector<vector<int>>> blocks;
    vector<vector<vector<int>>> blanks;
    blocks.push_back(table);
    blanks.push_back(game_board);
    int size = table.size();
    for(int i = 0;i<size;i++)
    {
        for(int j = 0;j<size;j++)
        {
            if(blocks[0][i][j] == 1)
                blocks = GetBlock(blocks,i,j,1);   
            if(blanks[0][i][j]==0)
                blanks = GetBlock(blanks,i,j,0);
        }
    }
    int nums = blanks.size();
    int c = 0;
    for(int i = 1;i<blanks.size();i++)
    {   
        for(int j = 1;j<blocks.size();j++)
        {
            if(blocks[j][0][0]==2)
                continue;
            for(int k = 0;k<4;k++)
            {
                int fill = Fill(blanks[i],blocks[j]);
                if(fill>0)
                {
                    answer +=fill;
                    blocks[j][0][0]=2;
                    blanks[i][0][0]=2;
                    break;
                }
                else
                {
                    blocks[j] = Rotate(blocks[j]);
                }
            }
            if(blanks[i][0][0]==2)
                break;
        }
    }
    return answer;
}