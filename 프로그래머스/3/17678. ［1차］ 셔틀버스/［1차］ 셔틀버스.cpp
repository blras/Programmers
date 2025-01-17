#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
int Ttoi(string s)
{
    int temp = (s[0]-'0')*600 + (s[1]-'0')*60+ (s[3]-'0')*10+(s[4]-'0');
    return temp;
}
string itoT(int x)
{
    string s;
    int temp = x/600;
    s.push_back(temp+'0');
    x = x%600;
    temp = x/60;
    s.push_back(temp+'0');
    s.push_back(':');
    x = x%60;
    temp = x/10;
    s.push_back(temp+'0');
    x = x%10;
    s.push_back(x+'0');
    return s;
}
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    queue<int> q;
    int size = timetable.size();
    sort(timetable.begin(),timetable.end());
    for(int i = 0;i<size;i++)
        q.push(Ttoi(timetable[i]));
    int time = 540-t;
    bool b = false;
    for(int i = 0;i<n;i++)
    {
        int count = 0;
        time += t;
        while(!q.empty())
        {
            int temp = q.front();
            if(temp<=time)
            {
                q.pop();
                count++;
                if(count>=m)
                {
                    if(i==n-1)
                    {
                        b=true;
                        answer = (itoT(temp-1));
                    }
                    break;
                }
            }
            else
                break;
        }
        
    }
    if(!b)
        answer = itoT(time);
    return answer;
}