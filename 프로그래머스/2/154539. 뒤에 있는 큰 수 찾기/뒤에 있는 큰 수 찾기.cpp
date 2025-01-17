#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> numbers) {
    int size = numbers.size();
    vector<int> answer (size,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i =0;i<size;i++)
    {
        pair<int,int> p = {numbers[i],i};
        while(!pq.empty())
        {
            pair<int,int> temp = pq.top();
            if(temp.first<numbers[i])
            {
                answer[temp.second]=numbers[i];
                pq.pop();
            }
            else
                break;
        }
        pq.push(p);
    }
    while(!pq.empty())
    {
        pair<int,int> temp = pq.top();
        answer[temp.second]=-1;
        pq.pop();
    }
    return answer;
}