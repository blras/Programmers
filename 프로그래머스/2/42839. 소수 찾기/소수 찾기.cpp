#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string numbers) {
    int answer = 0;
    string str = numbers;
    vector<int> nums;
    vector<bool> com (numbers.size(),true);
    sort(str.begin(),str.end());
    vector<bool> prime (10000000,true);
    for(int i = 2;i<prime.size();i++)
    {
        if(prime[i])
            for(int j = i*2;j<prime.size();j +=i)
            {
                prime[j]=false;
            }
    }
    prime[0] = false;
    prime[1] = false;
    for(int i = 0;i<com.size();i++)
    {
        do
        {
            string temp = "";
            for(int j = 0; j<str.size();j++)
            {
                if(com[j])
                    temp.push_back(str[j]);
            }
            int n = stoi(temp);
            if(find(nums.begin(),nums.end(),n)==nums.end())
                nums.push_back(n);
        }while(next_permutation(str.begin(),str.end()));
        com[i] = false;
    }
    for(int i = 0;i<nums.size();i++)
    {
        if(prime[nums[i]])
        {
            answer++;
        }
    }
    return answer;
}