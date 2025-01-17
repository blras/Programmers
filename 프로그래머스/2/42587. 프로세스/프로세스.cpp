#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int count = 0;
    vector<int> spro = priorities;
    queue<pair<int,int>> q;
    sort(spro.begin(),spro.end());
    for(int i = 0;i<priorities.size();i++)
    {
        pair<int,int> p = {priorities[i],i};
        q.push(p);
    }
    int l = 0;
    while(q.size()>0)
    {
        pair<int,int> p= q.front();
        q.pop();
        int temp = p.first;
        if(temp ==spro[spro.size()-1])
        {
            count++;
            if(p.second == location)
            {
                answer = count;
                break;
            }
            spro.pop_back();
        }
        else
            q.push(p);
        
    }
    return answer;
}