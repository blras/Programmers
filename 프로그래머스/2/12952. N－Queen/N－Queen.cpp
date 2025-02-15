#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
vector<pair<int,int>> vp;
int solution(int n) {
    int answer = 0;
    if(n==1)
        return 1;
    for(int i = 0;i<n;i++)
    {
        queue<vector<int>> q;
        vector<int> v = {i};
        q.push(v);
        while(!q.empty())
        {
            vector<int> tv = q.front();
            q.pop();
            int size = tv.size();
            for(int j = 0;j<n;j++)
            {
                bool able = true;
                for(int k =0;k<size;k++)
                {
                    int pos = (size-k + tv[k]);
                    int neg = (tv[k]-size+k);
                    if(j==pos||j==neg||j==tv[k])
                    {   
                        able =false;
                        break;
                    }
                }
                if(able)
                {
                    if(size<n-1)
                    {
                        vector<int> v = tv;
                        v.push_back(j);
                        q.push(v);
                    }
                    else
                        answer++;
                }
            }
        }
    }
    return answer;
}