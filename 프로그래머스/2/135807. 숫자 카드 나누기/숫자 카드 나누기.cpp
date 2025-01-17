#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;
int Cdiv(int a,int b)
{
    while(a>1)
    {
        int temp = a-b;
        if(temp == 0)
            return a;
        a = b>temp?b:temp;
        b = b<=temp?b:temp;
    }
    return 0;
}
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int size =arrayA.size();
    set<int> sA(arrayA.begin(),arrayA.end());
    set<int> sB(arrayB.begin(),arrayB.end());
    int a = -1;
    int b = -1;
    for(auto iter=sA.begin();iter!=sA.end();iter++)
    {
        if(a<0)
            a = *iter;
        else if(a>0)
            if(*iter%a!=0)
                a = Cdiv(*iter,a);
        if(a==0)
            break;
    }
    for(auto iter=sB.begin();iter!=sB.end();iter++)
    {
        if(b<0)
            b = *iter;
        else if(b>0)
            if(*iter%b!=0)
                b = Cdiv(*iter,b);
        if(b==0)
            break;
    }
    for(auto iter=sA.begin();iter!=sA.end();iter++)
    {
        if(b>0&&*iter%b==0)
        {
            b=0;
            break;
        }
    }
    for(auto iter=sB.begin();iter!=sB.end();iter++)
    {
        if(a>0&&*iter%a==0)
        {
            a=0;
            break;
        }
    }
    answer = a>b?a:b;
    return answer;
}