#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    long long temp = 1;
    long long m = 0;
    long long count = 0;
    set<int> s;
    for(int i = 1;i<=n;i++)
        s.insert(i);
    while(temp<k)
    {
        m++;
        temp *= m;
    }
    int N = n;
    while(m<N)
    {
        int a = *s.begin();
        answer.push_back(a);
        s.erase(a);
        N--;
    }
    int b = *s.begin();
    while(k>=0&&m>0&&temp>0)
    {
        temp /= m;
        long long a =temp;
        long long t = a;
        long long x = a;
        for(auto iter = s.begin();iter!=s.end();iter++)
        {
            int b = *iter;
            if(a>=k)
            {
                answer.push_back(b);
                s.erase(b);
                break;
            }
            else
            {
                t=a;
                a+=x;
            }
        }
        if(t<k)
            k-=t;
        m--;
        count++;
    }
    for(auto iter = s.begin();iter!=s.end();iter++)
    {
        int b = *iter;
        answer.push_back(b);
    }
    return answer;
}