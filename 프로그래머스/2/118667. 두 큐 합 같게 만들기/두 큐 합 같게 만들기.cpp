#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int solution(vector<int> queue1, vector<int> queue2) {
    long long answer = -2;
    long long sum = 0 ;
    long long sq1 = 0;
    long long sq2 = 0;
    queue<int> q1;
    queue<int> q2;
    int size = queue1.size();
    long long count = 0;
    for(int i = 0; i<size;i++)
    {
        q1.push(queue1[i]);
        q2.push(queue2[i]);
        sq1 += queue1[i];
        sq2 += queue2[i];
    }
    
    sum = sq1+sq2;
    
    if(sum%2 != 0)
    {
        answer = -1;
        return answer;
    }
    long long ts1 = sq1;
    long long ts2 = sq2;
    while(ts1 != ts2)
    {
        if(q1.front()>sum/2 || q2.front()>sum/2)
        {
            count = -1;
            break;
        }
        if(ts1>ts2)
        {
            int temp = q1.front();
            q1.pop();
            ts1 -= temp;
            ts2 += temp;
            q2.push(temp);
        }
        else
        {
          int temp = q2.front();
            q2.pop();
            ts2 -= temp;
            ts1 += temp;
            q1.push(temp);  
        }
        
        count++;
        if(count>size*3)
        {
            return -1;
        }
    }
    
    answer = count;
    return answer;
}