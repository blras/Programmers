#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> arr) 
{
    int answer = 0;
    sort(arr.rbegin(),arr.rend());
    int mul = arr[0];
    for(int i = 1;i<arr.size();i++)
    {
        int a = arr[i];
        int m = mul;
        while(m%a!=0)
        {   
            int x = m%a;
            m = a;
            a = x;
        }
        mul = mul*arr[i]/a;
    }
    answer = mul;
    return answer;
}