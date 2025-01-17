#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    queue<pair<int,int>> b;
    for(int i = 0;i<truck_weights.size();i++)
        q.push(truck_weights[i]);
    int temp = 0;
    int t = 0;
    while(!q.empty()||!b.empty())
    {
        t++;
        if(!b.empty())
        {
            pair<int,int> p =b.front();
            int x = p.first;
            int y = p.second;
            if(t>=x+bridge_length)
            {
                b.pop();
                temp-=y;
            }
        }
        if(!q.empty())
        {
            int a = q.front();
            if(temp+a<=weight&&b.size()<bridge_length)
            {
                b.push({t,a});
                q.pop();
                temp+=a;
            }
        }
    }
    answer = t;
    return answer;
}