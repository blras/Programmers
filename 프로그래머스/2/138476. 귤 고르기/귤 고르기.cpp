#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    sort(tangerine.begin(),tangerine.end());
    vector<int> counts;
    counts.push_back(0);
    int temp = 0;
    int init = tangerine[0];
    for(int i = 0;i<tangerine.size();i++)
    {
        if(init==tangerine[i])
            counts[temp]++;
        else
        {
            counts.push_back(1);
            temp++;
            init = tangerine[i];
        }
    }
    sort(counts.rbegin(),counts.rend());
    temp = 0;
    int sum = counts[0];
    answer++;
    while(sum<k)
    {
        answer++;
        temp++;
        sum = sum+counts[temp];
    }
    return answer;
}