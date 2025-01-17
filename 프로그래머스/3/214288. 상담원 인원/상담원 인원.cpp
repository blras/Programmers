#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>
using namespace std;
vector<queue<pair<int,int>>> v;
int Cons(int k,int n)
{
    queue<pair<int,int>> q = v[k];
    int t = 0;
    int r = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        if(pq.size()<n)
        {
            q.pop();
            if(t<p.first)
                t= p.first;
            pq.push(t+p.second);
            while(pq.top()<t&&!pq.empty())
                pq.pop();
        }
        else
        {
            int temp = pq.top();
            pq.pop();
            if(p.first<temp)
            {
                r = r+temp-p.first;
                t= temp;
            }
        }
    }
    return r;
}
int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = -1;
    queue<pair<int,int>> q;
    v = vector<queue<pair<int,int>>> (k,q);
    int wait =-1;
    for(int i = 0;i<reqs.size();i++)
    {
        pair<int,int> p = {reqs[i][0],reqs[i][1]};
        v[reqs[i][2]-1].push(p);
    }
    n -=k;
    set<vector<int>> memo;
    queue<pair<vector<int>,int>> qq;
    vector<int> vi (k,1);
    qq.push({vi,0});
    while(!qq.empty())
    {
        pair<vector<int>,int> temp = qq.front();
        qq.pop();
        if(memo.find(temp.first)!=memo.end())
            continue;
        memo.insert(temp.first);
        if(temp.second>=n)
        {
            int r = 0;
            for(int i = 0;i<k;i++)
            {
                r+=Cons(i,temp.first[i]);
                if(r>answer&&answer>=0)
                    break;
            }
            if(r<answer||answer<0)
            answer = r;
            continue;
        }
        for(int i = 0;i<k;i++)
        {
            vector<int> tv = temp.first;
            tv[i]++;
            qq.push({tv,temp.second+1});
        }
    }
    return answer;
}