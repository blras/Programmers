#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.rbegin(),citations.rend());
    int m = citations.size();
    for(int i = 0;i<m;i++)
    {
        if(citations[i]>=i+1&&citations[i+1]<=i+1)
        {
            answer =i+1;
            break;
        }
    }
    return answer;
}