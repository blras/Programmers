#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n) {
    int answer = 0;
    string vi = "";
    int de = n;
    while(de>0)
    {
        int temp  = de%2;
        string s = to_string(temp);
        vi =s+vi;
        de = de/2;
    }
    bool up = false;
    int b = 0;
    for(int i = vi.size()-1;i>0;i--)
    {
        if(!up)
            if(vi[i]=='1'&&vi[i-1]=='0')
            {
                vi[i]='0';
                vi[i-1]='1';
                b = i;
                up=true;
                break;
            }
    }
    if(up)
        sort(vi.begin()+b,vi.end());
    else
    {
        vi.insert(1,"0");
        sort(vi.begin()+1,vi.end());
    };
    int k = 0;
    int m = 0;
    while(k<vi.size())
    {
        int temp = vi[k]-'0';
        m = m*2 + temp;
        k++;
    }
    answer = m;
    return answer;
}