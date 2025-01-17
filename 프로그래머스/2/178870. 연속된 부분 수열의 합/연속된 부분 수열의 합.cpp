#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int size = sequence.size();
    vector<int> v (size,-1);
    int sum = 0;
    int s = 0;
    int e = 0;
    for(int i = 0;i<size;i++)
    {
        sum+=sequence[i];
        e=i;
        while(sum>=k&&s<size)
        {
            if(sum==k&&s<size)
                v[s]=e;
            sum-=sequence[s];
            s++;
        }
    }
    int temp = -1;
    s = 0;
    e = 0;
    for(int i =0;i<size;i++)
    {
        int len = v[i] - i;
        if(len>=0)
        {
            if(temp<0||(temp>=0&&len<temp))
            {
                temp = len;
                s = i;
                e = v[i];
            }
        }
    }
    answer = {s,e};
    return answer;
}