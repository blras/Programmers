#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    queue<vector<int>>q;
    vector<int> xy = {characterX*2,characterY*2,0};
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};
    vector<bool> memoX (101,0);
    vector<vector<bool>>memo (101,memoX);
    vector<int> cols (101,-1);
    vector<vector<int>> board (101,cols);
    for(int i = 0;i<rectangle.size();i++)
    {
        vector<int> rec = rectangle[i];
        for(int j = rec[1]*2;j<=rec[3]*2;j++)
        {
        for(int k = rec[0]*2;k<=rec[2]*2;k++)
            {
                if(j==rec[1]*2||j==rec[3]*2||k==rec[0]*2||k==rec[2]*2)
                {
                    if(board[j][k]==-1)
                        board[j][k] = 1;
                }
                else
                    board[j][k]=0;
            }
        }
    }
    q.push(xy);
    while(!q.empty())
    {   
        vector<int> tempv = q.front();
        q.pop();
        int x = tempv[0];
        int y = tempv[1];
        int move = tempv[2];
        memo[y][x]=true;
        if(x == itemX*2&&y==itemY*2)
        {
            answer = move;
            break;
        }
        for(int i = 0;i<4;i++)
        {
            int tempx = x+dx[i];
            int tempy = y+dy[i];
            if(tempx>=0&&tempx<101&&tempy>=0&&tempy<101)
            {
                if(board[tempy][tempx]==1&&!memo[tempy][tempx])
                {
                    int tempm = move+1;
                    vector<int> temp = {tempx,tempy,tempm};
                    q.push(temp);
                }
            }
        }
    }
    answer = answer/2;
    return answer;
}