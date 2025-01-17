#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<int> v;
    vector<vector<int>> nodes (n+1,v);
    vector<int> memo (n+1,-1);
    int size = roads.size();
    
    for(int i = 0;i<size;i++)
    {
        nodes[roads[i][0]].push_back(roads[i][1]);
        nodes[roads[i][1]].push_back(roads[i][0]);
    }
    
    queue<pair<int,int>> q;
    q.push({destination,0});
    while(!q.empty())
    {
        pair<int,int> p =q.front();
        q.pop();
        if(memo[p.first]>=0&&memo[p.first]<=p.second)
            continue;
        memo[p.first] = p.second;
        for(int i = 0;i<nodes[p.first].size();i++)
            q.push({nodes[p.first][i],p.second+1});
    }
    for(int i = 0;i<sources.size();i++)
        answer.push_back(memo[sources[i]]);
    return answer;
}