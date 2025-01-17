#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
map<string,vector<pair<string,int>>> MAP;
vector<bool> memo;
vector<string> a;
bool IsDone()
{
    for(int i = 0;i<memo.size();i++)
        if(!memo[i])
            return false;
    return true;
}
void DFS(string s)
{
    auto iter = MAP.find(s);
    if(iter ==MAP.end())
        return;
    a.push_back(iter->first);
    vector<bool> tm = memo;
    vector<string> ta = a;
    int k = 0;
    while(!IsDone()&&k<iter->second.size())
    {
        vector<pair<string,int>> temp = iter->second;
        a = ta;
        memo = tm;
        if(!memo[temp[k].second])
        {
            memo[temp[k].second]=true;
            DFS(temp[k].first);
        }
        k++;
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    memo = vector<bool> (tickets.size(),false);
    string root = "ICN";
    for(int i = 0;i<tickets.size();i++)
    {
        auto iter = MAP.find(tickets[i][0]);
        if(iter==MAP.end())
            MAP.insert({tickets[i][0],{{tickets[i][1],i}}});
        else
            iter->second.push_back({tickets[i][1],i});
        iter =MAP.find(tickets[i][1]);
        if(iter==MAP.end())
        {
            vector<pair<string,int>> p;
            MAP.insert({tickets[i][1],p});
        }
    }
    for(auto iter = MAP.begin();iter!=MAP.end();iter++)
        sort(iter->second.begin(),iter->second.end());
    DFS(root);
    answer = a;
    return answer;
}