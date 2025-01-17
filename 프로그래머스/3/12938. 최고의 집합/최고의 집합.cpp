#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int max = s;
    int min = 1;
    int k = s/n;
    int sub = s-k*n;
    if(k==0)
        return {-1};
    for(int i = 0;i<n;i++)
    {
        if(i<n-sub)
            answer.push_back(k);
        else
            answer.push_back(k+1);
    }
    return answer;
}