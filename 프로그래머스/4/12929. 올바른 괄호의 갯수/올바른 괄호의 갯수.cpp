#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    for(int i = 2;i<=n;i++)
    {
        int temp = 0;
        for(int j = 0;j<i;j++)
            temp+=v[i-j-1]*v[j];
        v.push_back(temp);
    }
    answer = v[n];
    return answer;
}