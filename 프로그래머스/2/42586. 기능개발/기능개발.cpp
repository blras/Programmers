#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> pro = progresses;
    queue<int> q;
    int size = pro.size();
    for(int i = 0;i<size;i++)
    {
        q.push(i);
    }
    int a = 0;
    while(a<pro.size())
    {
        int count = 0;
        for(int i = a;i<size;i++)
        {
            pro[i] += speeds[i];
            if(pro[i]>=100 && q.front()==i)
            {
                q.pop();
                a++;
                count++;
            }
        }
        if(count>0)
        {
            answer.push_back(count);
        }
    }
    return answer;
}