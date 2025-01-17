#include <string>
#include <vector>
#include <iostream>

using namespace std;
int dfs(vector<vector<int>>v, vector<bool> b,int k, int c)
{
    int answer = c;
    for(int i = 0;i<v.size();i++)
    {
        if(!b[i] &&k>=v[i][0])
        {
            b[i]=true;
            int a = k-v[i][1];
            int temp = dfs(v,b,a,c+1);
            b[i]=false;
            answer = temp>answer ? temp : answer;
        }
    }
    return answer;
}
int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<bool> memo(dungeons.size(),false);
    answer = dfs(dungeons,memo,k,answer);
    return answer;
}