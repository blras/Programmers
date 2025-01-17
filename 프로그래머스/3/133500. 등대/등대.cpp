#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> nodes;
vector<bool> memo;
int result;
void DFS(int n,int pre)
{
    for(int i=0; i< nodes[n].size();i++)
    {
        if(nodes[n][i]!=pre)
        {
            DFS(nodes[n][i],n);
            if(!memo[nodes[n][i]]&&!memo[n])
            {
                memo[n]=true;
                result++;
            }
        }
    }
}
int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    vector<int> v;
    nodes = vector<vector<int>> (n+1);
    memo = vector<bool> (n+1,false);
    result = 0;
    for(int i = 0;i<n-1;i++)
    {
        int x = lighthouse[i][0];
        int y = lighthouse[i][1];
        nodes[x].push_back(y);
        nodes[y].push_back(x);
    }
    DFS(1,1);
    answer = result;
    return answer;
}