#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <iostream>
using namespace std;
vector<vector<int>> nodes;
bool cmd(vector<int> a, vector<int> b)
{
    return a[2]<b[2];
}
bool BFS(int a,int b)
{
    queue<int> q;
    q.push(a);
    vector<bool> visit (nodes.size(),false);
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        if(temp == b)
            return true;
        visit[temp] = true;
        for(int i = 0;i<nodes[temp].size();i++)
        {
            if(!visit[nodes[temp][i]])
            {
                visit[nodes[temp][i]] =true;
                q.push(nodes[temp][i]);
            }
        }
    }
    return false;
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<vector<int>> edges = costs;
    int size = edges.size();
    sort(edges.begin(),edges.end(),cmd);
    vector<int> v;
    nodes = vector<vector<int>> (n,v);
    for(int i = 0;i<size;i++)
    {
        if(!BFS(edges[i][0],edges[i][1]))
        {
            nodes[edges[i][0]].push_back(edges[i][1]);
            nodes[edges[i][1]].push_back(edges[i][0]);
            answer+=edges[i][2];
        }
    }
    
    return answer;
}