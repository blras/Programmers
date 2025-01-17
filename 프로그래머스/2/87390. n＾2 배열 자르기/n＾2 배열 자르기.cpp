#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    long long x = left%n;
    long long y = left/n;
    for(long long i = left+1;i<=right+1;i++)
    {
        int a = i%n;
        int b = i/n+1;
        if(a==0)
        {
            a=n;
            b--;
        }
        if(b>a)
        {a=b;}
        answer.push_back(a);
    }
    return answer;
}