#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string,int> cmap;
    int size = clothes.size();
    vector<int> counts;
    
    
    for(auto a :clothes)
    {
        if(cmap.find(a[1])!=cmap.end())
            cmap[a[1]] = cmap[a[1]]+1;
        else
            cmap.insert({a[1],1});
    }
    for(auto a: cmap)
    {
        int val = a.second;
        counts.push_back(val);
    }
    
    size = counts.size();
    int k = 1;
    if(size == clothes.size())
    {
        for(int i = 0;i<size;i++)
            k = k*2;
        answer = k-1;
        return answer;
    }
    int temp= 0;
    for(int i = 1;i<=size;i++)
    {   
        vector<bool> v (size-i,false);
        v.insert(v.end(),i,true);
        do
        {
            int cal = 1;
            for(int j = 0;j<size;j++)
            {
                if(v[j])
                    cal*=counts[j];
            }
            answer+=cal;
        }while(next_permutation(v.begin(),v.end()));
    }
    return answer;
}