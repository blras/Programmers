#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> dots;
    vector<double> sizes;
    int y = k;
    dots.push_back(y);
    while(y>1)
    {
        if(y%2==0)
            y = y/2;
        else
            y = y*3 +1;
        dots.push_back(y);
    }
    for(int i = 1;i<dots.size();i++)
    {
        double m = dots[i]>dots[i-1] ? dots[i] : dots[i-1];
        double n = dots[i]<dots[i-1] ? dots[i] : dots[i-1];
        double size = (m-n)/2 + n;
        sizes.push_back(size);
    }
    int len = sizes.size();
    for(int i = 0;i<ranges.size();i++)   
    {
        int begin = ranges[i][0];
        int end = len + ranges[i][1];
        double integral = 0;
        if(end<begin)
            answer.push_back(-1);
        else
        {
            for(int j = begin;j<end;j++)
                integral +=sizes[j];
            answer.push_back(integral);
        }
    }
    return answer;
}