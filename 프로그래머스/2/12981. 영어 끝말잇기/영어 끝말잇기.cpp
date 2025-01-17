#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string,int> m;
    m.insert({words[0],0});
    char c = words[0][words[0].size()-1];
    for(int i = 1;i<words.size();i++)
    {
        int x = i+1;
        int a = 0;
        int b = 0;
        if(x%n==0)
        {
            a = n;
            b = x/n;
        }
        else
        {
            a=x%n;
            b= x/n+1;
        }
        if(words[i][0]==c)
        {
            if(m.find(words[i]) !=m.end())
            {
                answer = {a,b};
                break;
            }
            else
            {
                m.insert({words[i],i});
                c = words[i][words[i].size()-1];
            }
        }
        else
        {
            answer = {a,b};
            break;
        }
    }
    if(answer.size()==0)
        answer = {0,0};
    return answer;
}