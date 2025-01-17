#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(),times.end());

    long long s = 1;
    
    long long end = (long long)times[times.size() - 1]*n;

    long long mid;


    while (s<=end)
    {
        mid = (s + end)/2;
        long long comple = 0;
        for (int i = 0; i < times.size(); i++)
        {
            comple = comple + mid / times[i];
        }

        if (comple < n)
        {
            s = mid+1;
        }
        else
        {
            if (mid <= end)
            {
                answer = mid;
            }
            end = mid-1;
        }
    }


    return answer;
}