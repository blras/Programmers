#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int x, int y, int n) {
    int answer = -1;
    queue<pair<int,int>> q;
    vector<int> v (1000001,-1);
    q.push({x,0});
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        int a = p.first;
        int b = p.second;
        if(v[a]<0||v[a]>b)
            v[a]=b;
        else if (v[a]==b)
            continue;
        else
            b=v[a];
        if(a==y)
        {
            if(b<answer||answer<0)
                answer = b;
            continue;
        }
        else if(a>y)
            continue;
        for(int i = 1;i<=3;i++)
        {
            int temp = a*i;
            if(i==1)
                temp+=n;
            if(temp<=y)
                q.push({temp,b+1});
        }
    }
    return answer;
}