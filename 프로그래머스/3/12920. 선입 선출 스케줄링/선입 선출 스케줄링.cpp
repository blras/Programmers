#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> cores) {
    int answer = 0;
    int low = -1;
    int high = 2000000;
    int mid = 0;

    while(low+1<high)
    {
        mid = (low+high)/2;
        int count = cores.size();
        if(mid>0)
            for(int i = 0;i<cores.size();i++)
            {
                count+=mid/cores[i];
            }
        if(count<n)
            low = mid;
        else
            high = mid;
    }
    if(low==-1)
    {
        return n;
    }
    int count = cores.size();
    for(int i = 0;i<cores.size();i++)
    {
        count += low/cores[i];
    }
    
    
    for(int i = 0;i<cores.size();i++)
    {
        if((low+1)%cores[i]==0)
            count++;
        
        if(count==n)
        {
            return i+1;
            break;
        }
    }
    return answer;
}