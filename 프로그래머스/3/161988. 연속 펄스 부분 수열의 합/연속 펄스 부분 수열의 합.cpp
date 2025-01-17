#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    int size =sequence.size();
    vector<long long> pul1;
    vector<long long> pul2;
    
    int p = 1;
    long long c1 = 0;
    long long c2 = 0;
    for(int i = 0;i<size;i++)
    {
        if(c1<0)
            c1 = sequence[i]*p;
        else
            c1+=sequence[i]*p;
        if(c2<0)
            c2 = sequence[i]*-p;
        else
            c2+=sequence[i]*-p;
        p = -p;
        pul1.push_back(c1);
        pul2.push_back(c2);
    }
    

    
    sort(pul1.begin(),pul1.end());
    sort(pul2.begin(),pul2.end());
    answer = pul1[size-1]>=pul2[size-1]?pul1[size-1]:pul2[size-1];
    return answer;
}