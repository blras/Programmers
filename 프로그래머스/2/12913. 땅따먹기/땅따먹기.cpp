#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<vector<int>> land)
{
    int answer = 0;
    int size = land.size();
    vector<vector<int>> dy;
    dy.push_back(land[0]);
    for(int i = 1;i<size;i++)
    {
        vector<int> v;
        for(int j = 0;j<4;j++)
        {
            int temp = 0;
            for(int k=0;k<4;k++)
            {
                if(j!=k&&dy[i-1][k]>temp)
                    temp = dy[i-1][k];
            }
            v.push_back(temp+land[i][j]);
        }
        dy.push_back(v);
    }
    sort(dy[size-1].begin(),dy[size-1].end());
    answer = dy[size-1][3];
    return answer;
}