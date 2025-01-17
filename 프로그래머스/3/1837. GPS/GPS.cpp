#include <vector>
using namespace std;
vector<vector<int>> vv;
vector<vector<int>> memo;
vector<int> gps;
int e;
int BFS(int k,int n)
{
    if(memo[k][n]!=-2)
        return memo[k][n];
    int a = -1;
    if(k==e)
    {   
        if(n!=gps[k])
            return -1;
        else
        {
            memo[k][n]=0;
            return 0;
        }
    }
    for(int i = 0;i<vv[n].size();i++)
    {
        int t = BFS(k+1,vv[n][i]);
        if(t!=-1)
        {
            if(n!=gps[k])
                t+=1;
            if(a==-1||t<a)
                a=t;
        }
    }
    memo[k][n] = a;
    return a;
}
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    vector<int> v;
    vv =vector<vector<int>> (n+1,v);
    vector<int> me (n+1,-2);
    memo = vector<vector<int>> (k,me);
    e = k-1;
    gps = gps_log;
    for(int i = 0;i<m;i++)
    {
        int s = edge_list[i][0];
        int e = edge_list[i][1];
        vv[s].push_back(e);
        vv[e].push_back(s);
    }
    answer=BFS(0,gps_log[0]);
    return answer;
}