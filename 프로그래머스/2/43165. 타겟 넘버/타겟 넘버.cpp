#include <string>
#include <vector>

using namespace std;

void dfs(vector<int>vec, int num, int count, int target,int &answer)
{
    if (count == vec.size())
    {
        if (num == target)
        {
            answer = answer+1;
        }
        return;
    }

    dfs(vec, num+vec[count], count+1, target, answer);
    dfs(vec, num-vec[count], count+1, target, answer);
    return;
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    

    dfs(numbers, 0, 0, target, answer);

    return answer;
}