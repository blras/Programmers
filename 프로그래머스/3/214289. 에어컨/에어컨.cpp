#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = 0;
    int size = onboard.size();
    vector<int> m (51,100001);
    vector<vector<int>> memo (size,m);
    queue<vector<int>> q;
    q.push({0,0,temperature});
    while(!q.empty())
    {
        vector<int> v = q.front();
        q.pop();
        if(onboard[v[0]]&&(v[2]<t1||v[2]>t2))
            continue;
        if(memo[v[0]][v[2]+10]<=v[1])
            continue;
        memo[v[0]][v[2]+10] = v[1];
        if(v[0]==size-1)
            continue;
        int temp = v[2];
        if(temp<temperature)
            temp++;
        else if (temp>temperature)
            temp--;
        q.push({v[0]+1,v[1],temp});
        if(v[2]<t2)
            q.push({v[0]+1,v[1]+a,v[2]+1});
        if(v[2]>t1)
        {
            q.push({v[0]+1,v[1]+a,v[2]-1});
        }
        q.push({v[0]+1,v[1]+b,v[2]});
    }
    sort(memo[size-1].begin(),memo[size-1].end());
    answer = memo[size-1][0];
    return answer;
}