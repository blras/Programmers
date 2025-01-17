#include <string>
#include <vector>
#include <iostream>

using namespace std;
long long Getmetal(int w,int t, long long time)
{
    long long a = time/t;
    a = a/2 +a%2;
    a = a*w;
    return a; 
}
long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    int times = 0;
    long long low = -1;
    long long high = 10e14 * 3;
    long long mid = 0;
    long long sum = a+b;
    long long size = g.size();
    long long m = 0;
    long long answer = high;
    while(low<high)
    {
        mid = (low+high)/2;
        long long metal = 0;
        long long gsum=0;
        long long ssum=0;
        long long tsum = 0;
        for(int i = 0;i<size;i++)
        {
            long long temp = Getmetal(w[i],t[i],mid);
            
            gsum+=min((long long)g[i],temp);
            ssum+=min((long long)s[i],temp);
            metal+=min((long long)g[i]+s[i],temp);
            
        }
        if(metal>=sum&&gsum>=a&&ssum>=b)
        {
            answer = min(answer,mid);
            high = mid;
        }
        else
            low = mid+1;
        
    }
    
    return answer;
}