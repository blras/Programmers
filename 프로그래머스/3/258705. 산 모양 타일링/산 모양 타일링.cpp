#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    int answer = 0;
    int div = 10007;
    int pre = 0;
    vector<int> dy {1};
    vector<int> tdy{0};
    if(tops[0]==1)
    {
        dy.push_back(3);
        tdy.push_back(1);
    }
    else
    {
        dy.push_back(2);
        tdy.push_back(1);
    }
    for(int i = 1;i<=n;i++)
    {
        if(tops[i]==0)
        {
            int temp = dy[i]*2+tdy[i];
            int tt = dy[i]+tdy[i];
            temp%=div;
            tt%=div;
            dy.push_back(temp);
            tdy.push_back(tt);
        }
        else
        {
            int temp = dy[i]*3+tdy[i]*2;
            int tt = dy[i]+tdy[i];
            temp%=div;
            tt%=div;
            dy.push_back(temp);
            tdy.push_back(tt);
        }   
    }
    answer = (dy[n]+tdy[n])%div;
    return answer;
}