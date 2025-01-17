#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<long long> v (m,0);
    vector<vector<long long>> vec(n,v);
    vec[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0 && i == 0)
                continue;
            else if (j == 0 && i > 0)
            {
                vec[i][j] += vec[i - 1][j]%1000000007;
            }
            else if (i == 0 && j > 0)
            {
                vec[i][j] += vec[i][j - 1]%1000000007;
            }
            else
            {
                vec[i][j] = (vec[i][j - 1] + vec[i - 1][j])%1000000007;
            }
            for (int k = 0; k < puddles.size(); k++)
            {
                int x = puddles[k][0] - 1;
                int y = puddles[k][1] - 1;
                if (x == j && y == i)
                {
                    vec[i][j] = 0;
                    break;
                }
            }
        }
    }
    long long a = vec[n-1][m-1]%1000000007;
    answer  = a;
    
    return answer;
}