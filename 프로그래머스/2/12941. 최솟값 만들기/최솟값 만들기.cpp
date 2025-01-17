#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    vector<int> tempA = A;
    vector<int> tempB = B;
    sort(tempA.begin(),tempA.end());
    sort(tempB.begin(),tempB.end());
    for(int i = 0;i<tempA.size();i++)
    {
        int n = tempA[i];
        int m = tempB[tempB.size()-1-i];
        answer+=n*m;
    }

    return answer;
}