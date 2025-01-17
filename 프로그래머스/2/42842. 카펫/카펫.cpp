#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int xy = brown + yellow;
    int a = sqrt(xy);
    int end = xy/3;
    for(int i = a;i<=end;i++)
    {
        int x = i;
        int y = xy/x;
        if(x>=y && 2*x+2*y-4==brown && (x-2)*(y-2)==yellow)
        {
            answer.push_back(x);
            answer.push_back(y);
            break;
        }
    }
    return answer;
}