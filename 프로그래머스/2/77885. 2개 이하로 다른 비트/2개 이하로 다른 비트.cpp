#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<long long> bi;

long long FX(long long x)
{
    long long temp = x;
    long long y = 0;
    if(x%2==1)
    {
        long long k = temp+1;
        long long a = 0;
        long long b = 0;
        long long c = 1;
        while(x!=1)
        {
            x=x/2;
            a++;
            c=c*2;
        }
        while(k!=1)
        {
            k = k/2;
            b++;
        }
        if(b>a)
            y+=bi[b-1];
        else
        {
            long long t = temp - c;
            y += FX(t);
        }
    }
    else
        y +=1;
    return y;
}
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    int size = numbers.size();
    bi.push_back(1);
    for(int i = 1;i<=50;i++)
        bi.push_back(bi[i-1]*2);
    for(int i = 0;i<size;i++)
        answer.push_back(numbers[i]+FX(numbers[i]));

    return answer;
}