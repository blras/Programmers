#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int max = 100001;
    vector<long long> fibo = {0,1};
    long long div = 1234567;
    for(int i = 2;i<=n;i++)
    {
        long long a = (fibo[i-1]+fibo[i-2]) % div;
        fibo.push_back(a);
    }
    answer = fibo[n];
    return answer;
}