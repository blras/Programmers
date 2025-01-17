#include <iostream>
#include <string>
#include <deque>
using namespace std;

int solution(string s)
{
    int answer = -1;
    int size = s.size();
    int count=0;
    deque<char> dq;
    for(int i = 0;i<size;i++)
    {
        dq.push_back(s[i]);
    }
    char c = dq.front();
    dq.pop_front();
    count++;
    while(dq.size()!=0)
    {
        if(dq.front()==c)
        {
            dq.pop_front();
            size -= 2;
            count -= 2;
            if(dq.size()>0)
            {
                c = dq.back();
                dq.pop_back();
            }
            else
                break;
        }
        else
        {
            dq.push_back(c);
            c = dq.front();
            dq.pop_front();
            count++;
        }
        if(count==size)
            break;
     }
    
    if(size==0)
        answer = 1;
    else
        answer = 0;
    
    return answer;
}