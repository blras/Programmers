#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;
bool cmp(vector<int> a, vector<int> b)
{
    return (a.size()<b.size());
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> set;
    vector<bool> memo (100001,false);
    stack<char> sta;
    int temp = 0;
    int iter = -1;
    for(int i = 0;i<s.size();i++)
    {
        if(s[i]=='{')
        {
            sta.push(s[i]);
            if(sta.size()>1)
            {
                vector<int> v;
                set.push_back(v);
                iter++;
            }
        }
        else if(s[i]=='}')
        {
            sta.pop();
            if(sta.size()>0)
            {
                set[iter].push_back(temp);
                temp = 0;
            }
        }
        else if(sta.size()>1)
        {
            if(isdigit(s[i]))
            {
                temp = temp*10;
                int k = s[i]-'0';
                temp += k;
            }
            else
            {
                set[iter].push_back(temp);
                temp = 0;
            }
        }
    }
    sort(set.begin(),set.end(),cmp);

    iter = 0;
    for(int i = 0;i<set.size();i++)
    {
        for(int j = iter;j<set[i].size();j++)
        {
            if(!memo[set[i][j]])
            {
                memo[set[i][j]] = true;
                answer.push_back(set[i][j]);
                break;
            }
        }
    }
    return answer;
}