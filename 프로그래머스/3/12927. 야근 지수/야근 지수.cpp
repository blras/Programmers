#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int>pq;
    for(int i = 0;i<works.size();i++)
    {
        pq.push(works[i]);
    }
    for(int i = 0;i<n;i++)
    {
        int k = pq.top();
        pq.pop();
        if(k>0)
            k--;
        else
            break;
        pq.push(k);
    }
    while(!pq.empty())
    {
        int k = pq.top();
        pq.pop();
        answer+=k*k;
    }
    return answer;
}