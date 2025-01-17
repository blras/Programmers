#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<int> a(26,0);
    vector<vector<int>> alpha(26,a);
    for(int i = 0;i<orders.size();i++)
    {
        sort(orders[i].begin(),orders[i].end());
    }
    for(int i = 0;i<course.size();i++)
    {
        int c = course[i];
        map<string,int> co;
        for(int j = 0;j<orders.size();j++)
        {
            if(orders[j].size()>=c)
            {
                vector<bool> v(orders[j].size()-c,false);
                v.insert(v.end(),c,true);
                do{
                    string temp = "";
                    for(int k = 0;k<orders[j].size();k++)
                    {
                        if(v[k])
                            temp +=orders[j][k];
                    }
                    auto iter = co.find(temp);
                    if(iter != co.end())
                    {iter->second = iter->second+1;}
                    else
                    {co.insert({temp,1});
                    if(c==2){cout<<temp<<",";}}
                }while(next_permutation(v.begin(),v.end()));    
            }
        }
        string maxCo;
        int max = 0;
        for(auto iter = co.begin() ; iter!=co.end(); iter++)
        {
            if(iter->second>max)
            {
                max = iter->second;
            }
        }
        for(auto iter = co.begin() ; iter!=co.end(); iter++)
        {
            if(max>1&&iter->second==max)
            {
                answer.push_back(iter->first);
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}