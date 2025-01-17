#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,vector<pair<int,int>>> g;
    map<string,int> t;
    int size = genres.size();
    for(int i = 0;i<size;i++)
    {
        if(t.find(genres[i])!=t.end())
        {
            t[genres[i]]+=plays[i];
            g[genres[i]].push_back({plays[i],i});
        }
        else
        {
            t.insert({genres[i],plays[i]});
            g.insert({genres[i],{{plays[i],i}}});
        }
    }
    vector<pair<int,string>> v;
    for(auto iter = t.begin();iter!=t.end();iter++)
    {
        pair<int,string> p = {iter->second,iter->first};
        v.push_back(p);
    }
    sort(v.rbegin(),v.rend());
    
    for(int i = 0;i<v.size();i++)
    {
        string s = v[i].second;
        int count = 0;
        int temp = -1;
        sort(g[s].rbegin(),g[s].rend());
        for(auto j = g[s].begin();j!=g[s].end();j++)
        {
            int a = j->second;
            if(temp>=0&&j->first == plays[answer[temp]])
            {
                int t = a;
                for(int k =temp;k<answer.size();k++)
                {
                    t = answer[k];
                    if(a<answer[k])
                    {
                        answer[k] = a;
                        a = t;
                    }
                }
                if(count<2)
                {
                    answer.push_back(a);
                    count++;
                }
            }
            else if(count<2)
            {
                answer.push_back(a);
                temp = answer.size()-1;
                count++;
            }
        }
    }
    return answer;
}