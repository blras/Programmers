#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<string> v;
vector<vector<int>> memo;
int BFS(int x,int y)
{
    queue<vector<int>> q;
    q.push({x,y,0});
    while(!q.empty())
    {
        vector<int> temp = q.front();
        q.pop();
        int mx = temp[0];
        int my = temp[1];
        if(memo[mx][my]>0)   
        {
            memo[mx][my] = memo[mx][my]<temp[2]?memo[mx][my]:temp[2];
            continue;
        }
        else
            memo[mx][my] = temp[2];
        if(v[mx][my]=='G')
            continue;
        int ux = mx+1;
        int dx = mx-1;
        int ry = my-1;
        int ly = my+1;
        for(int i = mx;i>=0;i--)
        {
            ux--;
            if(v[i][my]=='D')
            {ux++; break;}
        }
        for(int i = mx;i<v.size();i++)
        {   
            dx++;
            if(v[i][my]=='D')
            {dx--;break;}
        }
        for(int i = my;i>=0;i--)
        {
            ly--;
            if(v[mx][i]=='D')
            {ly++;break;}
        }
        for(int i = my;i<v[mx].size();i++)
        {
            ry++;
            if(v[mx][i]=='D')
            {ry--;break;}
        }
        vector<int> up = {ux,my,temp[2]+1};
        vector<int> down = {dx,my,temp[2]+1};
        vector<int> left = {mx,ly,temp[2]+1};
        vector<int> right = {mx,ry,temp[2]+1};
        q.push(up);
        q.push(down);
        q.push(left);
        q.push(right);
    }
    return 0;
}
int solution(vector<string> board) {
    int answer = 0;
    vector<int> b (board[0].size(),0);
    memo = vector<vector<int>> (board.size(),b);
    v = board;
    int x = -1;
    int y = -1;
    int gx = -1;
    int gy = -1;
    for(int i = 0;i<board.size();i++)
    {
        for(int j = 0;j<board[i].size();j++)
        {
            if(board[i][j]=='R')
            {
                x = i;
                y = j;
            }
            if(board[i][j]=='G')
            {
                gx = i;
                gy = j;
            }
        }
    }
    BFS(x,y);
    if(memo[gx][gy]==0)
        answer = -1;
    else
        answer = memo[gx][gy];
    return answer;
}