#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> s (gems.begin(),gems.end());
    unordered_map<string,int> m;
    int num = s.size();
    int size =gems.size();
    int start = 0;
    int end = 0;
    int min = size;
    int i = 0;
    while(true)
    {
        for(i = end;i<size;i++)
        {
            m[gems[i]]++;
            if(m.size()>=num)
            {
                end = i;
                break;
            }
        }
        if(i == size)
            break;
        for(i = start;i<size;i++)
        {
            if(m[gems[i]]==1)
            {
                start = i;
                break;
            }
            m[gems[i]]--;
        }
        if(end-start<min)
        {
            min = end-start;
            answer = {start+1,end+1};
        }
        m.erase(gems[start]);
        start++;
        end++;
    }
    return answer;
}