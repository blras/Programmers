#include <vector>
#include <queue>

using namespace std;

int MAXDIGIT = 100;
vector<vector<bool>> memo(MAXDIGIT, vector<bool>(MAXDIGIT, 0));

int serch(vector<vector<int>> vec,int m,int n,int a,int b)
{
    int size = 0;
    queue<pair<int,int>> q;
    q.push(pair<int,int>(a,b));
    vector<int> dx = {0,0, -1,1 };
    vector<int> dy = { -1,1,0,0 }; 

    while (!q.empty()) {
        pair<int,int> v = q.front();
        q.pop();

        if (memo[v.first][v.second])
            continue;

        size++;
        memo[v.first][v.second] = true;

        for (int i = 0; i < 4; i++)
        {
            int x = v.second + dx[i];
            int y = v.first + dy[i];

            if (x >= 0 && n > x && y >= 0 && m > y)
            {
                if (vec[y][x] == vec[a][b] && !memo[y][x])
                {
                    q.push(pair<int, int>(y, x));
                }
            }
        }
    }
    return size;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            memo[i][j] = false;
    }

    int number_of_area = 0;
    int max_size_of_one_area = 0;
    //unordered_multimap<int, int> color;
    int temp_size = 0;
    vector<vector<bool>> dis(m,vector<bool>(n,0));


    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!memo[i][j] && picture[i][j] != 0)
            {
                number_of_area++;
                temp_size = serch(picture, m,n,i, j);
                if (temp_size > max_size_of_one_area)
                {
                    max_size_of_one_area = temp_size;
                }
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}