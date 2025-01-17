#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int num = n;
    int answer = 0;
    int small;
    int large;
    if(a>b)
    {
        small = b;
        large = a;
    }
    else
    {
        small = a;
        large = b;
    }

    while(num>0)
    {
        answer++;
        if(large - small == 1 && large%2 == 0)
            break;
        else
        {
            if(small%2!=0)
                small = small/2+1;
            else
                small = small/2;
            if(large%2!=0)
                large = large/2+1;
            else
                large = large/2;
            num = num/2;
        }
    }

    return answer;
}