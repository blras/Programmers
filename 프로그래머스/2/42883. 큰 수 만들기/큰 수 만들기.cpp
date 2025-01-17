#include <string>
#include <vector>
#include <iostream>
#include <deque>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int size = number.size();
    deque<char> dp;
    int n =0;
    while(k>0)
    {
        if(n<size)
        {
            while(!dp.empty())
            {
                char temp = dp.back();
                if(temp<number[n])
                {
                    dp.pop_back();
                    k--;
                    if(k<=0)
                        break;
                }
                else
                    break;
            }
            dp.push_back(number[n]);
            n++;
        }
        else
        {
            dp.pop_back();
            k--;
        }
    }
    while(!dp.empty())
    {
        char temp = dp.front();
        dp.pop_front();
        answer.push_back(temp);
    }
    for(int i = n;i<size;i++)
        answer.push_back(number[i]);
    return answer;
}