#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    vector<vector<bool>> visited;
    vector<int> vec(places.size(), 1);
    vector<int>dx{0,0,1,-1};
    vector<int>dy{1,-1,0,0};

    queue < pair<int, int>> s;

    for (int i = 0; i < places.size(); i++)
    {
        vector<bool> b;
        visited.push_back(b);
        for (int j = 0; j < places[i].size(); j++)
            visited[i].push_back(false);
    }


    for (int i = 0; i < places.size(); i++)
    {
        for (int j = 0; j < places[i].size(); j++)
        {
            for (int k = 0; k < places[i][j].size(); k++)
            {
                if (places[i][j][k] == 'P')
                {
                    s.push(pair<int, int>(j, k));
                    while (!s.empty())
                    {
                        pair<int, int> v = s.front();
                        int y = v.first;
                        int x = v.second;
                        s.pop();
                        if (abs(k - x) + abs(j - y) > 1)
                        {
                            continue;
                        }

                        if (visited[y][x])
                            continue;

                        visited[y][x] = true;
                        for (int d = 0; d < 4; d++)
                        {
                            int a, b = 0;
                            a = x + dx[d];
                            b = y + dy[d];
                            if (a >=0 && 5 > a && b >=0 && 5 > b)
                            {
                                if (places[i][b][a] == 'O')
                                {
                                    s.push(pair<int, int>(b, a));
                                }
                                if (places[i][b][a] == 'P'&&!visited[b][a])
                                {
                                    vec[i] = false;
                                    break;
                                }
                            }
                        }
                    }
                    for (int c = 0; c < 5; c++)
                    {
                        for (int d = 0; d < 5; d++)
                        {
                            visited[c][d] = false;
                        }
                    }
                }
            }
        }
    }
    answer = vec;
    return answer;
}