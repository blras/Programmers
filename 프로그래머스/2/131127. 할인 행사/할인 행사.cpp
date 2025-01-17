#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    vector<string> v;
    for(int i = 0;i<want.size();i++)
    {
        for(int j = 0;j<number[i];j++)
            v.push_back(want[i]);
    }
    sort(v.begin(),v.end());

    for(int i = 0;i<=discount.size()-10;i++)
    {
        vector<string> temp(discount.begin()+i,discount.begin()+10+i);
        sort(temp.begin(),temp.end());
        if(v==temp)
            answer++; 
    }
    return answer;
}