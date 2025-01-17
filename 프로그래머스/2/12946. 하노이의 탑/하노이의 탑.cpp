#include <string>
#include <vector>
#include <stack>
using namespace std;
vector<vector<int>> movetop(int begin, int end,int k)
{
    int mid =0;
    for(int i = 1;i<=3;i++)
    {
        if(i!= begin&&i!=end)
            mid = i;
    }
    vector<vector<int>> v1;
    vector<vector<int>> v2;
    vector<int> last {begin,end};
    if(k>1)
    {
        v1 = movetop(begin,mid,k-1);
        v2 = movetop(mid,end,k-1);
        v1.push_back(last);
        v1.insert(v1.end(),v2.begin(),v2.end());
    }
    else
    {
        v1.push_back(last);
    }
    return v1;
}
vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    answer = movetop(1,3,n);
    return answer;
}