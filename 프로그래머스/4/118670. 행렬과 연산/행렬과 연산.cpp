#include <string>
#include <vector>
#include <deque>
using namespace std;
int height;
int width;
deque<int> lcol;
deque<int> rcol;
deque<int> c;
vector<deque<int>> dq;
void ShiftRow()
{
    int temp = c.back();
    int l = lcol.back();
    int r = rcol.back();
    c.pop_back();
    c.push_front(temp);
    lcol.pop_back();
    lcol.push_front(l);
    rcol.pop_back();
    rcol.push_front(r);
}
void Rotate()
{
    int l = lcol.front();
    int r = rcol.back();
    int templ = r;
    int tempr = l;
    if(width>2)
    {
        int f = c.front();
        int b = c.back();
        templ = dq[b].front();
        tempr = dq[f].back();
        dq[f].pop_back();
        dq[f].push_front(l);
        dq[b].pop_front();
        dq[b].push_back(r);
    }
    lcol.pop_front();
    lcol.push_back(templ);
    rcol.pop_back();
    rcol.push_front(tempr);
}
vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer;
    int size = operations.size();
    height = rc.size();
    width = rc[0].size();
    for(int i = 0;i<height;i++)
    {
        deque<int> d;
        for(int j = 1;j<width-1;j++)
            d.push_back(rc[i][j]);
        dq.push_back(d);
        c.push_back(i);
        lcol.push_back(rc[i][0]);
        rcol.push_back(rc[i][width-1]);
    }
    for(int i = 0;i<size;i++)
    {
        if(operations[i][0]=='R')
            Rotate();
        else
            ShiftRow();
    }
    while(!lcol.empty())
    {
        int l = lcol.front();
        int r = rcol.front();
        deque<int> d = dq[c.front()];
        lcol.pop_front();
        rcol.pop_front();
        c.pop_front();
        vector<int> v;
        v.push_back(l);
        while(!d.empty())
        {
            int temp = d.front();
            d.pop_front();
            v.push_back(temp);
        }
        v.push_back(r);
        answer.push_back(v);
    }
    return answer;
}