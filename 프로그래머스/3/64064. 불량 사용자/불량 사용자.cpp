#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;
vector<vector<int>> banned;
set<set<int>> ss;
int BFS(set<int> s,int k)
{
    int answer = 0;
    if(k<banned.size())
    {
        for(int i = 0;i<banned[k].size();i++)
        {
            
            set<int> ts = s;
            ts.insert(banned[k][i]);
            if(k==banned.size()-1&&ts.size()==banned.size())
                ss.insert(ts);
            else
                BFS(ts,k+1);
        }
    }
    return answer;
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<int> v;
    banned = vector<vector<int>> (banned_id.size(),v);
    queue<vector<int>> q;
    for(int i = 0;i<banned_id.size();i++)
    {
        for(int j=0;j<user_id.size();j++)
        {
            if(banned_id[i].size()==user_id[j].size())
            {
                int size = banned_id[i].size();
                bool b = true;
                for(int k = 0;k<size;k++)
                    if(banned_id[i][k]!='*'&&banned_id[i][k]!=user_id[j][k])
                        b=false;
                if(b)
                    banned[i].push_back(j);
            }
        }
    }
    set<int> s;
    BFS(s,0);

    answer = ss.size();
    return answer;
}