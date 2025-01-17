#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
vector<vector<int>>graph;
vector<int>cost;
vector<int>spot;
int ans;
vector<int> dfs(vector<int>vec, queue<int> q)
{
    vector<int> v = vec;
    if(spot[v[0]]>0)
        v[1]++;
    else
        v[2]++;
    if(v[1]<=v[2])
        return v;
    if(v[1]>ans)
        ans = v[1];
    for(int i = 0;i<graph[v[0]].size();i++)
        q.push(graph[v[0]][i]);
    for(int i = 0;i<q.size();i++)
    {
        int c = q.front();
        q.pop();
        vector<int> temp = {c,v[1],v[2]};
        dfs(temp,q);
        q.push(c);
    }
    return vec;
}
int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    vector<int> v;
    graph = vector<vector<int>> (info.size(),v);
    queue<int> q;
    ans = 0;
    for(int i = 0;i<edges.size();i++)
    {
        int parent = edges[i][0];
        int child = edges[i][1];
        graph[parent].push_back(child);
    }
    for(int i = 0;i<info.size();i++)
    {
        if(info[i]==0)
            spot.push_back(1);
        else
            spot.push_back(-1);
    }
    vector<int> temp = {0,0,0};
    dfs(temp,q);
    answer  = ans;
    return answer;
}