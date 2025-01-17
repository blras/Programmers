#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
vector<vector<int>> b;
vector<vector<bool>> memo;
vector<int> cards;
vector<int> dx = {0,1,0,-1};
vector<int> dy = {1,0,-1,0};
int R;
int C;
int BFS(int num)
{
    vector<int> v {R,C,0};
    queue<vector<int>> q;
    q.push(v);
    while(!q.empty())
    {
        vector<int> tv = q.front();
        int r = tv[0];
        int c = tv[1];
        int temp = tv[2];
        q.pop();
        if(b[r][c]==num)
        {
            R=r;
            C=c;
            b[r][c]=0;
            return temp+1;
        }
        for(int i = 0;i<4;i++)
        {
            int x = r+dx[i];
            int y = c+dy[i];
            if(x>=0&&x<4&&y>=0&&y<4)
            {
                if(!memo[x][y])
                {
                    memo[x][y]=true;
                    vector<int> vv {x,y,temp+1};
                    q.push(vv);
                }
            }
            int tx = r;
            int ty = c;
            while(tx+dx[i]>=0&&tx+dx[i]<4&&ty+dy[i]>=0&&ty+dy[i]<4)
            {
                tx+=dx[i];
                ty+=dy[i];
                if(b[tx][ty]!=0)
                    break;
            }
            if(!memo[tx][ty])
            {   
                memo[tx][ty]=true;
                vector<int> vvv {tx,ty,temp+1};
                q.push(vvv);
            }
        }
    }
}
int solution(vector<vector<int>> board, int r, int c) 
{
    int answer = 1001;
    vector<bool> iscards (6,0);
    R = r;
    C = c;
    for(int i = 0;i<4;i++)
        for(int j = 0;j<4;j++)
            if(board[i][j]>0)
                iscards[board[i][j]-1] = true;
    for(int i = 0;i<6;i++)
        if(iscards[i])
            cards.push_back(i+1);
    vector<bool> v (4,0);
    vector<vector<bool>> tm (4,v);
    do{
        b = board;
        int temp = 0;
        R = r;
        C = c;
        for(int i = 0;i<cards.size();i++)
        {
            memo = tm;
            temp += BFS(cards[i]);
            memo = tm;
            temp += BFS(cards[i]);
        }
        answer = answer<temp?answer:temp;
    }while(next_permutation(cards.begin(),cards.end()));
    return answer;
}