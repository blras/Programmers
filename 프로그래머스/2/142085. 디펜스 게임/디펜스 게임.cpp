#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int size = enemy.size();
    int N = n;
    int K = k;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 0;i<size;i++)
    {
        pq.push(enemy[i]);
        if(K>0)
            K--;
        else
        {
            int temp = pq.top();
            pq.pop();
            if(N<temp)
                break;
            N-=temp;
        }
        answer  = i+1;
    }
    return answer;
}