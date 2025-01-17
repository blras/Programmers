#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    queue<pair<int,int>> s;
    vector<vector<int>> node(n, vector<int>(n, 0));
    vector<bool> visited(n, false);
    vector<int> length(n, 0);

    for (int i = 0; i < edge.size(); i++)
    {
        node[edge[i][0] - 1][edge[i][1] - 1] = 1;
        node[edge[i][1] - 1][edge[i][0] - 1] = 1;
    }

    s.push(pair<int, int>(0, 0));

    while (!s.empty())
    {

        int v = s.front().second;
        int p = s.front().first;
        s.pop();

        if (visited[v])
            continue;
        if(v!=0)
            length[v] = length[p] + 1;
        visited[v] = true;

        for (int j = 0; j < node[v].size(); j++)
        {
            if (!visited[j] && node[v][j] == 1)
            {
                //cout << j << " ";
                s.push(pair<int, int>(v, j));
            }
        }
    }

    int len = 0;
    for (int i = 0; i < length.size(); i++)
    {
        if (len == length[i])
            answer++;
        else if (length[i] > len)
        {
            len = length[i];
            answer = 1;
        }
    }
        
    return answer;
}