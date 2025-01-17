#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int storey) {
    int answer = -1;
    queue<pair<int,int>> q;
    q.push({storey,0});
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        if(p.second>=answer&&answer>0)
            continue;
        int k = p.first%10;
        if(p.first/10>0)
        {
            pair<int,int> t1 = {p.first/10,p.second+k};
            pair<int,int> t2 = {(p.first/10)+1,p.second+10-k};
            q.push(t1);
            q.push(t2);
        }
        else if(k>5)
        {
            pair<int,int> t = {(p.first/10)+1,p.second+10-k};
            q.push(t);
        }
        else
        {
            if(answer<0||p.second+k<answer)
                answer =p.second+k;
            if(answer<0||p.second+10-k<answer)
                answer =p.second+10-k;
        }
    }
    return answer;
}