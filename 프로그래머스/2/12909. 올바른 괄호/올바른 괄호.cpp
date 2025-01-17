#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<int> bra;
    for(int i = 0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
            bra.push(1);
        }
        else
        {
            if(bra.size()==0)
            {
                answer = false;
                return answer;
                break;
            }
            else
                bra.pop();
        }
    }
    if(bra.size()==0)
        answer = true;
    else
        answer = false;
    return answer;
}