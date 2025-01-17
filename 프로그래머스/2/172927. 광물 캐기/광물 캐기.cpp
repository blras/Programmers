#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    queue<pair<vector<int>,pair<int,int>>> q;
    map<vector<int>,int> memo;
    q.push({picks,{0,0}});
    int size = minerals.size();
    while(!q.empty())
    {
        pair<vector<int>,pair<int,int>> p = q.front();
        q.pop();
        auto iter = memo.find(p.first);
        if(iter!=memo.end())
        {
            if(p.second.second>=iter->second)
                continue;
            else
                iter->second = p.second.second;
        }
        else
            memo.insert({p.first,p.second.second});
        
        for(int i = 0;i<3;i++)
        {
            if(p.first[i]>0)
            {
                int temp = p.second.second;
                int count = p.second.first;
                for(int j = 0;j<5;j++)
                {
                    if(count>=size)
                        break;
                    if(minerals[count] == "diamond")
                    {
                        if(i==2)
                            temp+=25;
                        else if (i==1)
                            temp+=5;
                        else
                            temp++;
                    }
                    else if(minerals[count] == "iron")
                    {
                        if(i==2)
                            temp+=5;
                        else
                            temp++;
                    }
                    else
                        temp++;
                    count++;
                }
                if(count>=size)
                {
                    if(answer==0||answer>temp)
                        answer = temp;
                    continue;
                }
                vector<int> v = p.first;
                v[i]--;
                if(v[0]<=0&&v[1]<=0&&v[2]<=0)
                {
                    if(answer==0||answer>temp)
                        answer = temp;
                    continue;
                }
                q.push({v,{count,temp}});
            }
        }
    }
    return answer;
}