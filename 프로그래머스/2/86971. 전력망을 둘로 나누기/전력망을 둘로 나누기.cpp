#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> tree, vector<bool> &visited,int n,int k)
{
    queue<int> q;

    int count = 0;

    q.push(n);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        if (visited[v])
            continue;

        visited[v] = true;
        count++;

        for (int i = 0; i < tree.size(); i++)
        {
            if (i == k)
                continue;
            if (tree[i][0] - 1 == v)
                q.push(tree[i][1] - 1);
            else if (tree[i][1] - 1 == v)
                q.push(tree[i][0] - 1);
        }
    }
    return count;
}


int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    queue<int> q;
    //node *head = new node;
    //head->next = nullptr;
    vector<bool>visited;

    for (int i = 0; i < n; i++)
        visited.push_back(false);

    for (int i = 0; i < wires.size(); i++)
    {
        vector<int> count;
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == false)
            {
                count.push_back(bfs(wires, visited, j,i));
            }
        }
        if (count.size() > 1)
        {
            int a = abs(count[0] - count[1]);
                if (a < answer)
                    answer = a;
        }
        for (int i = 0; i < n; i++)
            visited[i]=false;
    }

   
    return answer;
}