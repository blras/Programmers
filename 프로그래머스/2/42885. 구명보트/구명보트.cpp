#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int size = people.size();
    int temp = size;
    vector<bool> memo (size,false);
    sort(people.begin(),people.end());
    for(int i = 0;i<size;i++)
    {
        if(!memo[i]&&people[i]<=limit/2)
        {
            for(int j = temp-1;j>i;j--)
            {
                if(!memo[j] &&people[i]+people[j]<=limit)
                {
                    answer++;
                    memo[i]=true;
                    memo[j]=true;
                    temp =j+1;
                    break;
                }
            }
        }
        if(!memo[i])
        {
            memo[i]=true;
            answer++;
        }
    }
    return answer;
}