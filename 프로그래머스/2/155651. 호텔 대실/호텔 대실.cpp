#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<pair<int,int>> v;
    int size = book_time.size();
    for(int i =0;i<size;i++)
    {
        int k1 = 0;
        int k2 = 0;
        for(int j = 0;j<5;j++)
        {
            if(j!=2)
            {
                int t1 = book_time[i][0][j]-'0';
                int t2 = book_time[i][1][j]-'0';
                if(j==0)
                {
                    t1*=600;
                    t2*=600;
                }
                else if(j==1)
                {
                    t1*=60;
                    t2*=60;
                }
                else if(j==3)
                {
                    t1*=10;
                    t2*=10;
                }
                k1+=t1;
                k2+=t2;
            }
        }
        v.push_back({k1,k2+10});
    }
    sort(v.begin(),v.end());
    int time = 0;
    for(int i = 0;i<size;i++)
    {
        time = v[i].first;
        while(!pq.empty())
        {
            int t = pq.top();
            if(t<=time)
                pq.pop();
            else
                break;
        }
        pq.push(v[i].second);
        if(pq.size()>answer)
            answer = pq.size();
    }
    return answer;
}