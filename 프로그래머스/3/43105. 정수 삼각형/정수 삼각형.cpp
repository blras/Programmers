#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> v;
    vector<int>v0;
    v0.push_back(triangle[0][0]);
    v.push_back(v0);
    for(int i = 0;i<triangle.size()-1;i++)
    {
        vector<int>tempv;
        int temp0 = v[i][0]+triangle[i+1][0];
        tempv.push_back(temp0);
        for(int j = 1;j<triangle[i+1].size()-1;j++)
        {
            int temp = triangle[i+1][j];
            int b = (v[i][j-1]>v[i][j])?v[i][j-1]:v[i][j];
            temp+=b;
            tempv.push_back(temp);
        }
        int tempe = v[i][triangle[i].size()-1]+triangle[i+1][triangle[i+1].size()-1];
        tempv.push_back(tempe);
        v.push_back(tempv);
    }
    int m = v.size()-1;
    sort(v[m].begin(),v[m].end());
    answer = v[m][v[m].size()-1];
    return answer;
}