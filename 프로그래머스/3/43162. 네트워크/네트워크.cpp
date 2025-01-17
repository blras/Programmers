#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool>visited(computers.size(),0);
    for(int i = 0;i<computers.size();i++)
    {
        queue<int> q;
        if(!visited[i])
        {
            answer++;
            visited[i] = true;
            q.push(i);
            while(!q.empty())
            {
                int n = q.front();
                q.pop();
                for(int j =0;j<computers[n].size();j++)
                {
                    if(n!=j&&computers[n][j]==1&&!visited[j])
                    {
                        visited[j]=true;
                        q.push(j);
                    }
                }
            }
        }
    }
    return answer;
}