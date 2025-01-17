#include <iostream>
#include<vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;

    int height = board.size();
    int width = board[0].size();
    vector<int> v (width,0);
    vector<vector<int>> squre (height,v);
    vector<int> dx = {0,-1,-1};
    vector<int> dy = {-1,0,-1};
    
    queue<pair<int,int>> q;
    
    for(int i = 0;i<height;i++)
    {
        for(int j = 0;j<width;j++)
        {
            if(board[i][j])
            {
                int temp = -1;
                for(int k = 0;k<3;k++)
                {
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if(x>=0&&x<height&&y>=0&&y<width)
                    {
                        if(temp<0||squre[x][y]<temp)
                            temp = squre[x][y];
                    }
                    else
                    {
                        temp=0;
                        break;
                    }
                }
                if(temp>=0)
                    squre[i][j]=temp+1;
                else
                    squre[i][j]=1;
            }
        }
    }
    int M = 0;
    for(int i = 0;i<height;i++)
    {
        for(int j = 0;j<width;j++)
        {
            if(squre[i][j]>M)
                M=squre[i][j];
        }
    }
    answer = M*M;
    return answer;
}