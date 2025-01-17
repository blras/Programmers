#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
int solution(vector<int> sticker)
{
    int size = sticker.size();
    int answer = 0;
    vector<bool> memo (size,true);
    vector<int> dy1 (size,0);
    vector<int> dy2 (size,0);
    dy1[0]=sticker[0];
    dy2[0]=0;
    if(size>1)
    {
        dy1[1] = dy1[0];
        dy2[1]=sticker[1];
    }
    for(int i = 2;i<size;i++)
    {
        if(i==size-1)
            dy1[i] = dy1[i-2]>dy1[i-1]?dy1[i-2]:dy1[i-1];
        else
            dy1[i] = dy1[i-2]+sticker[i]>dy1[i-1]?dy1[i-2]+sticker[i]:dy1[i-1];
        dy2[i] = dy2[i-2]+sticker[i]>dy2[i-1]?dy2[i-2]+sticker[i]:dy2[i-1];
    }
    answer = dy1[size-1]>dy2[size-1]?dy1[size-1]:dy2[size-1];
    return answer;
}