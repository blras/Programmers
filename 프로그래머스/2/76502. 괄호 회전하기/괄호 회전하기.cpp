#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> q;
    for(int i = 0;i<s.size();i++)
    {
        for(int j = i;j<(s.size()+i);j++)
        {
            int t = j;
            if(j>=s.size())
                t = j-s.size();
            if(s[t]=='('||s[t]=='{'||s[t]=='[')
                q.push(s[t]);
            else if(q.empty())
            {
                q.push(s[t]);
                break;
            }
            else if(!q.empty())
            {
                char c = q.top();
                if(c=='('&&s[t]==')')
                    q.pop();
                else if(c=='{'&&s[t]=='}')
                    q.pop();
                else if(c=='['&&s[t]==']')
                    q.pop();
                else
                    break;
            }
        }
        if(q.empty())
        {
            answer++;
        }
        while(!q.empty())
            q.pop();
    }
    return answer;
}