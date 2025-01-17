#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(string x, string y)
{
    string s1 = x+y;
    string s2 = y+x;
    return s1>s2;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for (int i = 0; i < numbers.size(); i++)
        v.push_back(to_string(numbers[i]));
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
        answer += v[i];
    if(answer[0]=='0')
        answer = "0";
    return answer;
}