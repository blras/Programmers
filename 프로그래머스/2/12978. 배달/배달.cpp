#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<int> v (51,-1);
    vector<int>tv;
    vector<vector<int>> edges (51,tv);
    int size = road.size();
    int n = 0;
    for(int i = 0;i<size;i++)
    {
        edges[road[i][0]].push_back(i);
        edges[road[i][1]].push_back(i);
    }
    vector<bool> memo (N+1,0);
    priority_queue<pair<int,int>> pq;
    pq.push({1,0});
    while(!pq.empty())
    {
        pair<int,int> p = pq.top();
        pq.pop();
        if(v[p.first]<0||p.second<v[p.first])
            v[p.first]=p.second;
        if(p.second>K)
            continue;
        for(int j=0;j<edges[p.first].size();j++)
        {
            int k = edges[p.first][j];
            int t = road[k][0]==p.first?road[k][1]:road[k][0];
            if(v[t]<0||v[t]>p.second+road[k][2])
            {
                pair<int,int>temp ={t,p.second+road[k][2]};
                pq.push(temp);
            }
        }
    }
    for(int i = 1;i<=N;i++)
    {
        if(v[i]<=K&&v[i]>=0)
            answer++;
    }
    return answer;
}