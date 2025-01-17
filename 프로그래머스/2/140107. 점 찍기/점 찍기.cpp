#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    int x = (d/k)+1;
    int y = x;
    for(int i = 0;i<=x;i++)
    {
        long long ak = i*k;
        for(int j = y;j>=i;j--)
        {
            long long bk = j*k;
            if(sqrt(ak*ak+bk*bk)<=d)
            {
                y = j;
                answer+=(j-i)*2;
                answer++;
                break;
            }
        }
    }
    return answer;
}