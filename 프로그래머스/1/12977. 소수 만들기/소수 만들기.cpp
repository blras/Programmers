#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) 
{
    vector<bool> p;
    for (int i = 0; i < 3000; i++)
    {
        p.push_back(false);
    }
    vector<int> prime;
    prime.push_back(2);
    prime.push_back(3);
    prime.push_back(5);
    p[2] = true;
    p[3] = true;
    p[5] = true;
    for (int i = 7; i < 2998; i = i + 2)
    {
        for (int j = 1; j < prime.size(); j++)
        {
            if (i % prime[j] == 0)
            {
                i = i + 2;
                j = 0;
            }
        }
        prime.push_back(i);
        p[i] = true;
    }
    int answer = -1;
    vector<int> q;
    int n = 0;
    int temp = 0;
    for (int i = 0; i < nums.size()-2; i++)
    {
        for (int j = i + 1; j < nums.size()-1; j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                n = nums[i] + nums[j] + nums[k];
                if (p[n])
                {
                    temp++;
                }
            }
        }
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
   // cout << "Hello Cpp" << endl;
    answer = temp;
    return answer;
}