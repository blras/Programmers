#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<int> q;
    vector<queue<int>> graph (words.size()+1,q);
    vector<string> v;
    bool t = false;
    v.push_back(begin);
    for(int i = 0;i <words.size();i++)
    {
        if(words[i]==target)
            t=true;
        v.push_back(words[i]);
    }
    if(!t)
        return 0;
    vector<bool> memo (v.size(),false);
    
    for(int i = 0;i<v.size();i++)
    {
        for(int j = i+1;j<v.size();j++)
        {
            int df = 0;
            for(int k = 0;k<v[i].size();k++)
            {
                if(v[i][k]!=v[j][k])
                {
                    df++;
                    if(df>1)
                        break;
                }
            }
            if(df==1)
            {
                graph[i].push(j);
                graph[j].push(i);
            }
        }
    }
    queue<pair<int,int>> a;
    a.push({0,0});
    while(!a.empty())
    {
        pair<int,int> p = a.front();
        a.pop();
        int x = p.first;
        int c = p.second;
        if(memo[x])
            continue;
        else
            memo[x]=true;
        if(v[x]==target)
        {
            if(answer>c||answer==0)
                answer = c;
            continue;
        }
        while(!graph[x].empty())
        {
            int temp = graph[x].front();
            graph[x].pop();
            a.push({temp,c+1});
        }
    }
    return answer;
}