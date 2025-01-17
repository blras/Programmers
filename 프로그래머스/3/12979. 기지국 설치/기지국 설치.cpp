#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int size = stations.size();
    int d = w*2+1;
    int e = 1;
    for(int i=0;i<size;i++)
    {
        int k = stations[i]-w-e;
        if(k>0)
        {
            int a = k/d;
            if(k%d!=0)
                a+=1;
            answer+=a;
        }
        e = stations[i]+w+1;
    }
    int k = n-e+1;
    if(k>0)
    {
        int a = k/d;
        if(k%d!=0)
            a+=1;
        answer+=a;
    }
    return answer;
}