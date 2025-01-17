#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool QueueSerch(queue<string> q, string s)
{
    while(!q.empty())
    {
        string str = q.front();
        q.pop();
        if(str == s)
            return true;
    }
    return false;
}
queue<string> SortQueue (queue<string> q,string s)
{
    queue<string> result;
    while(!q.empty())
    {
        string str = q.front();
        q.pop();
        if(str != s)
            result.push(str);
    }
    result.push(s);
    return result;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    queue<string> q;
    for(int i =0;i<cities.size();i++)
    {
        transform(cities[i].begin(),cities[i].end(),cities[i].begin(),::tolower);
        if(QueueSerch(q,cities[i]))
        {
            answer++;
            q = SortQueue(q,cities[i]);
        }
        else
        {
            answer+=5;
            if(q.size()<cacheSize)
                q.push(cities[i]);
            else if(q.size()>=cacheSize && cacheSize>0)
            {
                q.pop();
                q.push(cities[i]);
            }
        }
    }

    return answer;
}