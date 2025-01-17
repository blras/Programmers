#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> pads;
vector<vector<vector<int>>> memo;
string nums;
int DFS(int l,int r,int k)
{
    if(k>=nums.size())
        return 0;
    if(memo[k][l][r]>0)
        return memo[k][l][r];
    int t = nums[k]-'0';
    int left = pads[l][t];
    int right = pads[r][t];
    if(t!=r)
        left+=DFS(t,r,k+1);
    if(t!=l)
        right+=DFS(l,t,k+1);
    if(t==l)
    {
        memo[k][l][r] = left;
        return left;
    }
    if(t==r)
    {
        memo[k][l][r] = right;
        return right;
    }
    int a =left<right?left:right;
    memo[k][l][r] = a;
    return a;
}
int solution(string numbers) {
    int answer = 0;
    int size = numbers.size();
    vector<int> v (10,0);
    vector<vector<int>> vv (10,v) ;
    memo = vector<vector<vector<int>>> (size,vv);
    nums = numbers;
    pads = {{1,7,6,7,5,4,5,3,2,3},
            {7,1,2,4,2,3,5,4,5,6},
            {6,2,1,2,3,2,3,5,4,5},
            {7,4,2,1,5,3,2,6,5,4},
            {5,2,3,5,1,2,4,2,3,5},
            {4,3,2,3,2,1,2,3,2,3},
            {5,5,3,2,4,2,1,5,3,2},
            {3,4,5,6,2,3,5,1,2,4},
            {2,5,4,5,3,2,3,2,1,2},
            {3,6,5,4,5,3,2,4,2,1}};
    answer = DFS(4,6,0);
    return answer;
}