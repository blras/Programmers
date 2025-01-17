#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
int solution(vector<int> topping) {
    int answer = 0;
    int size = topping.size();
    vector<int> v (10001,0);
    set<int> s;
    set<int> es;
    for(int i=0;i<size;i++)
    {
        es.insert(topping[i]);
        v[topping[i]-1] = i;
    }
    int b = es.size();
    int n = 0;
    for(int i = 0;i<size;i++)
    {
        s.insert(topping[i]);
        if(v[topping[i]-1] == i)
        {
            b--;
            n++;
        }
        if(s.size()==b)
            answer++;
        else if(s.size()>b)
            break;
    }
    return answer;
}