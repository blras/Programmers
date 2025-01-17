#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<long long> vec;
    vec.push_back(1);
    vec.push_back(2);
    for(int i = 2;i<n;i++)
    {
        long long temp = vec[i-1]+vec[i-2];
        vec.push_back(temp%1234567);
    }
    answer = vec[n-1];
    return answer;
}