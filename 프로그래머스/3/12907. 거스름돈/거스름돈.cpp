#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;

    int size = money.size();
    sort(money.begin(),money.end());
    int start = money[0];
    vector<int> an (n+1,0);
    
    for(int i =0; i<size; i++)
    {
        an[money[i]]++;
        for(int j = money[i];j<=n;j++)
        {
            if(j>=money[i])
            {
                an[j]+=an[j-money[i]];
            }
        }
    }
    
    answer = an[n];
    return answer;
}