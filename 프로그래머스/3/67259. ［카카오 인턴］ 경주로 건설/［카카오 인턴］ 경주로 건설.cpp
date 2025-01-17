#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int max = 999999;
    vector<vector<vector<int>>>dynamic;
    queue<vector<int>> q;
    for(int i = 0;i<board.size();i++)
    { 
        vector<vector<int>> v;
        dynamic.push_back(v);
        for(int j = 0;j<board[i].size();j++)  
        {
            vector<int>vec = {max,max,max,max};
            dynamic[i].push_back(vec);
        }
    }
    vector<int>dx ={1,0,-1,0};
    vector<int>dy ={0,1,0,-1};
    int n = board.size();  
    dynamic[0][0][0] = 0;
    dynamic[0][0][1] = 0;
    dynamic[0][0][2] = 0;
    dynamic[0][0][3] = 0;
    vector<int> root = {0,0,-1,0};
    q.push(root);
    while(!q.empty())
    {
        vector<int> node = q.front();
        int nx = node[0];
        int ny = node[1];
        q.pop();
        for(int i = 1;i<=4;i++)
        {
            int temp = node[3];
            int x = node[0]+dx[i-1];
            int y = node[1]+dy[i-1];
            if(x>=0&&x<n&&y>=0&&y<n)
            {
                if(board[x][y]==0)
                {
                    temp += 100;
                    if(node[2]==1||node[2]==3)
                        if(i==2||i==4)
                            temp+=500;
                    if(node[2]==2||node[2]==4)
                        if(i==1||i==3)
                            temp+=500;
                            
                    if(dynamic[x][y][i-1]>temp)
                    {
                        dynamic[x][y][i-1] = temp;
                        vector<int> v = {x,y,i,temp};
                        q.push(v);
                    }
                }
            }
        }
    }
    
    sort(dynamic[n-1][n-1].begin(),dynamic[n-1][n-1].end());
    answer = dynamic[n-1][n-1][0];
    return answer;
}