#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int N = 1;
    if(n>1)
        N=(n*(n+1))/2;
    vector<vector<int>> v;
    for(int i = 0;i<n;i++)
    {
        vector<int> tv (i+1,0);
        v.push_back(tv);
    }
    int temp =1;
    vector<int> dx = {0,1,-1};
    vector<int> dy = {1,0,-1};
    int d = 0;
    int x = 0;
    int y = 0;
    for(int i = 1;i<=N;i++)
    {
        v[y][x] = i;
        if(y+dy[d]<0||y+dy[d]>=n||x+dx[d]<0||x+dx[d]>=v[y].size())
        {
            d++;
            d%=3;
        }
        else if(v[y+dy[d]][x+dx[d]]!=0)
        {
            d++;
            d%=3;
        }
        x = x+dx[d];
        y = y+dy[d];
    }
    for(int i = 0;i<v.size();i++)
        for(int j = 0;j<v[i].size();j++)
            answer.push_back(v[i][j]);
    return answer;
}