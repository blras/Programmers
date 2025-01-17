#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<int> Heap(vector<int> v)
{
    vector<int> h = v;
    int k = h.size()-1;
    while(k!=0)
    {
        if(h[k]<h[k/2])
        {
            int temp = h[k/2];
            h[k/2] = h[k];
            h[k] = temp;
            k = k/2;
        }
        else
            break;
    }
    return h;
}
vector<int> DeleteHeap(vector<int> v)
{
    vector<int> h = v;
    h[1] = h[h.size()-1];
    h.pop_back();
    int size = h.size()-1;
    int k = 3;
    while(k<=size)
    {
        if(h[k-1]<h[k])
        {
            k= k-1;
        }
        if(h[k]<h[k/2])
        {
            int temp = h[k/2];
            h[k/2] = h[k];
            h[k] = temp;
            k = k*2+1;
        }
        else
            break;
    }
    if(h.size()==3)
    {
        if(h[1]>h[2])
        {
            int temp = h[2];
            h[2] = h[1];
            h[1] = temp;
        }
    }
    return h;
}
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i = 0;i<scoville.size();i++)
    {
        q.push(scoville[i]);
    }
    while(q.top()<K)
    {
        if(q.size()<2)
        {
            answer = -1;
            break;
        }
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        a = a+ b*2;
        q.push(a);
        answer++;
    }
    
    return answer;
}