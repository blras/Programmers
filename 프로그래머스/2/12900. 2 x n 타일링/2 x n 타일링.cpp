#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int div = 1000000007;
    vector<int> dy = {0,1,2};
    for(int i = 3;i<=n;i++)
    {
        int temp = (dy[i-1]+dy[i-2])%div;
        dy.push_back(temp);
    }
    answer = dy[n];
    return answer;
}