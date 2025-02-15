#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> M;
vector<vector<int>> dy;
int Getm(int x,int y)
{
    int a=0;
    for(int i = x;i<y;i++)
    {
        int temp = dy[x][i]+dy[i+1][y]+(M[x][0]*M[i][1]*M[y][1]);
        if(a==0)
            a=temp;
        else
            a=a<temp?a:temp;
    }
    return a;
}
int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    M = matrix_sizes;
    int size = M.size();
    vector<int> v (size,0);
    dy = vector<vector<int>> (size,v);
    for(int i = 0;i<size;i++)
    {
        for(int j = 0;j<size-i;j++)
        {
            int k = j+i;
            dy[j][k] = Getm(j,k);
        }
    }
    answer = dy[0][size-1];
    return answer;
}