#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer (prices.size(),0);
    stack<pair<int,int>> s;
    for(int i =0;i<prices.size();i++)
    {
        bool b = true;
        while(!s.empty()&&b)
        {
            pair<int,int> p = s.top();
            if(p.second>prices[i])
            {
                answer[p.first] = i - p.first;
                s.pop();
            }
            else
                b=false;
            
        }
        s.push({i,prices[i]});
    }
    while(!s.empty())
    {
        pair<int,int> p = s.top();
        s.pop();
        answer[p.first] = answer.size()-1-p.first;
    }
    return answer;
}