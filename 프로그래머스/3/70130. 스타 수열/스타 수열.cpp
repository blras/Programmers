#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int solution(vector<int> a) {
    int answer = 0;
    int size = a.size();
    vector<bool> memo (size,false);
    vector<int> mode (size,0);
    vector<int> nums;
    for(int i = 0;i<size;i++)
    {
        mode[a[i]] +=1;
        if(!memo[a[i]]&&mode[a[i]]>1)
        {
            nums.push_back(a[i]);
            memo[a[i]] = true;
        }
    }
    if(size<2)
        return 0;
    for(int i = 0;i<nums.size();i++)
    {
        int inter = nums[i];
        int count = 0;
        vector<bool> tmemo (size,false);
        bool temp = false;
        bool intering = false;
        if(mode[inter]*2<=answer)
            continue;
        for(int j = 0;j<size;j++)
        {
            if(a[j]==inter)
            {
                if(temp)
                {
                    count+=2;
                    temp = false;
                }
                else if(!intering)
                    intering = true;
            }
            else if (intering)
            {
                intering =false;
                count+=2;
            }
            else
                temp = true;
        }
        if(count>answer)
            answer = count;
    }
    return answer;
}