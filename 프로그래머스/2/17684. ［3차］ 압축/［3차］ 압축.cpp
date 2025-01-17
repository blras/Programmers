#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    map<string,int> dic;
    vector<int> answer;
    for(int i = 0;i<26;i++)
    {
        char c = 'A'+i;
        string s;
        s.push_back(c);
        pair<string,int> p = {s,i+1};
        dic.insert(p);
    }
    int size = msg.size();
    string temp;
    for(int i = 0;i<size;i++)
    {
        int jumpi = i;
        temp.clear();
        for(int j = 1;j<=size-i;j++)
        {
            string s = msg.substr(i,j);
            if(dic.find(s)!=dic.end())   
            {
                temp=s;
                jumpi = i+j-1;
            }
            else if(dic.find(s)==dic.end()&&!temp.empty())
            {
                auto iter = dic.find(temp);
                answer.push_back(iter->second);
                pair<string,int> p = {s,dic.size()+1};
                dic.insert(p);
                break;
            }
        }
        i = jumpi;
    }
    if(!temp.empty())
    {
        auto iter = dic.find(temp);
        answer.push_back(iter->second);
    }
    return answer;
}