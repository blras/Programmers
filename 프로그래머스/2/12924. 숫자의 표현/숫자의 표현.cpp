#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 1;
    int k = 2;
    while(k*k + k <=n*2)
    {
        if(k%2==1)
        {
            int temp = n/k;
            if(k*temp==n)
                answer++;
        }
        else
        {
            int temp = n/k;
            int half = k/2;
            int sum = 0;
            int start = temp-half+1;
            for(int i =0;i<k;i++)
            {
                if(sum>=n)
                    break;
                sum = sum + start + i;
            }
            if(sum==n)
                answer++;
        }
        k++;
    }
    return answer;
}