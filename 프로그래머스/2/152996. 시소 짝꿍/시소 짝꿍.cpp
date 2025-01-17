#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    int M = 1001;
    sort(weights.begin(),weights.end());
    int size = weights.size();
    vector<long long> v (M,0);
    vector<bool> memo (M,false);
    for(int i = 0;i<size;i++)
            v[weights[i]]++;
    for(int i = 0;i<size;i++)
    {
        if(v[weights[i]]>1&&!memo[weights[i]])
        {
            answer+=v[weights[i]]*(v[weights[i]]-1)/2;
            memo[weights[i]]=true;
        }
        if(weights[i]*2<M&&v[weights[i]*2]>0)
            answer+=v[weights[i]*2];
        if(weights[i]%3==0&&weights[i]/3*4<M&&v[weights[i]/3*4]>0)
            answer+=v[weights[i]/3*4];
        if(weights[i]%2==0&&weights[i]/2*3<M&&v[weights[i]/2*3]>0)
            answer+=v[weights[i]/2*3];
    }
    return answer;
}