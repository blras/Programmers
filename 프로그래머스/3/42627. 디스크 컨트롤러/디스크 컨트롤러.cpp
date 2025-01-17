#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

struct cmp
{
    bool operator()(vector<int> a,vector<int>b)
    {
        return (a[1]>b[1]);
    }
};
bool greatercmp(vector<int> a,vector<int>b)
{
    if(a[0]==b[0])
        return (a[1]>b[1]);
    return (a[0]>b[0]);
}
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    long long sum = 0;
    int size = jobs.size();
    sort(jobs.begin(),jobs.end(),greatercmp);
    vector<vector<int>> job = jobs;
    priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
    
    int endtime = 0;
    int protime = 0;
    
    while(!pq.empty()||!job.empty())
    {
        if(!job.empty())
        {
            while(!job.empty()&&job[job.size()-1][0]<=endtime)
            {
                vector<int> v = job.back();
                job.pop_back();
                pq.push(v);
            }
            if(pq.empty())
            {
                vector<int> v = job.back();
                endtime = v[0]+v[1];
                protime = v[1];
                sum +=protime;
                job.pop_back();
            }
        }
        if(!pq.empty())
        {
            vector<int> v = pq.top();
            pq.pop();
            endtime +=v[1];
            int pro = endtime - v[0];
            sum +=pro;
        }   
    }
    answer = sum/size;
    return answer;
}