#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int size = stones.size();
    set<int> s;
    vector<int>v;
    for(int i = 0;i<size;i++)
        s.insert(stones[i]);
    for(auto iter = s.begin();iter!=s.end();iter++)
        v.push_back(*iter);
    int l= 0;
    int r = v.size();
    int m = (l+r)/2;
    while(l<r)
    {
        int temp = 0;
        for(int i = 0;i<size;i++)
        {
            if(stones[i]<=v[m])
            {
                temp++;
                if(temp>=k)
                    break;
            }
            else
                temp = 0;
        }
        if(temp<k)
            l = m+1;
        else if (temp>=k)
            r = m-1;
        m = (l+r)/2;
    }

    while(true)
    {
        int temp = 0;
        for(int i = 0;i<size;i++)
        {
            if(stones[i]<=v[m])
            {
                temp++;
                if(temp>=k)
                    return v[m];
            }
            else
                temp = 0;
        }
        m++;
    }
    return answer;
}