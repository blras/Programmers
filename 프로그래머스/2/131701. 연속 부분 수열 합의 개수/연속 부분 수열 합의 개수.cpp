#include <string>
#include <vector>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    vector<bool> nums (500501,false);
    int size = elements.size();
    for(int i = 0;i<size;i++)
    {
        int temp = 0;
        for(int j = 0;j<size;j++)
        {
            int k = i+j;
            if(k>=size)
                k-=size;
            temp +=elements[k];
            if(!nums[temp])
            {
                nums[temp] = true;
                answer++;
            }
        }
    }
    return answer;
}