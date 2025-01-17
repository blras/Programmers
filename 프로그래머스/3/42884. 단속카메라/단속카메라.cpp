#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int size = routes.size();
    vector<bool> memo (size,false);
    vector<pair<int,int>> r;
    for(int i = 0;i<size;i++)
    {
        pair<int,int> p;
        p.first = routes[i][0]<routes[i][1]?routes[i][0]:routes[i][1];
        p.second = routes[i][0]>=routes[i][1]?routes[i][0]:routes[i][1];
        r.push_back(p);
    }
    sort(r.begin(),r.end());
    int count = 0;
    int n = 0;
    while(count<size)
    {
        if(!memo[n])
            count++;
        else
        {
            n++;
            continue;
        }
        memo[n]=true;
        int m = r[n].second;
        for(int i = n;i<size;i++)
        {
            if(!memo[i]&&m>=r[i].first)
            {
                count++;
                memo[i]=true;
                if(r[i].second<m)
                    m = r[i].second;
            }
        }
        n++;
        answer++;
    }
    return answer;
}