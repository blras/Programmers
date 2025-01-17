#include <cmath>
#include <iostream>
using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    long long k = 0;
    long long c = 0;
    long long nw = w;
    long long nh = h;
    while(nh != 0)
    {
        c = nw%nh;
        nw = nh;
        nh = c;
    }


    answer = (long long)w* (long long)h - w - h + nw ;
    return answer;
}