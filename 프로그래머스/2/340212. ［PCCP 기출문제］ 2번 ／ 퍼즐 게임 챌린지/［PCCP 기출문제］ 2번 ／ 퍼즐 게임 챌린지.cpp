#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int size = diffs.size();
    vector<int> v = diffs;
    sort(v.rbegin(),v.rend());
    int r = v[0];
    int l = 1;
    while(r>l)
    {
        int m = (r+l)/2;
        long long t = 0;
        int pt = 0;
        bool solved = true;
        for(int i = 0;i<size;i++)
        {
            if(m>=diffs[i])
                t += times[i];
            else
            {
                int repeat = diffs[i]-m;
                t+=(times[i]+pt)*repeat+times[i];
            }
            pt = times[i];
            if(t>limit)
            {
                solved = false;
                break;
            }
        }
        if(solved)
            r = m;
        else
            l = m+1;
    }
    int level = l;
    bool solved = true;
    answer = level;
    return answer;
}