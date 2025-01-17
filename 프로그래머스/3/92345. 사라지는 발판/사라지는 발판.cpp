#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> dx ={1,0,-1,0};
vector<int> dy ={0,1,0,-1};
pair<int,bool> Move(vector<vector<int>>board,pair<int,int>a,pair<int,int>b)
{
    pair<int,bool> k;
    bool move = false;
    int x = a.first;
    int y = a.second;
    if(board[x][y]==0)
        return {0,false};
    else
        k.first++;
    int temp = 0;
    bool tb = false;
    for(int i = 0;i<4;i++)
    {
        int tx = x+dx[i];
        int ty = y+dy[i];
        if(tx>=0&&tx<board.size()&&ty>=0&&ty<board[0].size())
        {
            vector<vector<int>> v =board;
            if(v[tx][ty]==1)
            {
                v[x][y] = 0;
                pair<int,int> pa ={tx,ty};
                pair<int,bool> p =Move(v,b,pa);
                if(!p.second&&!tb)
                {
                    temp = p.first;
                    tb = true;
                }
                else if(p.second&&!tb)
                {
                    if(p.first>temp)
                        temp = p.first;
                }
                else if(!p.second&&tb)
                {
                    if(p.first<temp)
                        temp = p.first;
                }
                move = true;
            }
        }
    }
    k.first+=temp;
    k.second = tb;
    if(move == false)
    {
        k.first = 0;
        k.second = false;
    }
    return k;
}
int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = -1;
    pair<int,bool> p = Move(board,{aloc[0],aloc[1]},{bloc[0],bloc[1]});
    answer =p.first;
    return answer;
}