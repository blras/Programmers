#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int merges[2501];
string sells[2501];
vector<string> stov(string str)
{
    vector<string> v;
    istringstream ss (str);
    string temp;
    while(getline(ss,temp,' '))
        v.push_back(temp);
    return v;
}
int GetMerge(int n)
{
    if(merges[n]==-1)
        return n;
    else
        return merges[n]=GetMerge(merges[n]);
}
void Merging(int n1,int n2)
{
    int m1 = GetMerge(n1);
    int m2 = GetMerge(n2);
    if(m1==m2)
        return;
    merges[m2] = m1;
    if(sells[m1].empty()&&!sells[m2].empty())
        sells[m1] = sells[m2];
    else
        sells[m2] = sells[m1];
    return;
}
vector<string> solution(vector<string> commands) {
    vector<string> answer;
    memset(merges,-1,sizeof(merges));
    for(int i = 0;i<commands.size();i++)
    {
        stringstream ss(commands[i]);
        string com;
        ss>>com;
        if(com=="UPDATE")
        {
            if(count(commands[i].begin(), commands[i].end(), ' ') == 3)
            {
                int r;
                int c;
                string val;
                ss>>r>>c>>val;
                int n = GetMerge((r-1)*50+c-1);
                sells[n] = val;
            }
            else
            {
                string val1;
                string val2;
                ss>>val1>>val2;
                for(int j = 0;j<2500;j++)
                {
                    int n = GetMerge(j);
                    if(sells[n]==val1)
                        sells[n] = val2;
                }
            }
        }
        else if(com=="MERGE")
        {
            int r1;
            int c1;
            int r2;
            int c2;
            ss>>r1>>c1>>r2>>c2;
            Merging((r1-1)*50+c1-1,(r2-1)*50+c2-1);
        }
        else if(com=="UNMERGE")
        {
            int r;
            int c;
            ss>>r>>c;
            int n = GetMerge((r-1)*50+c-1);
            string val = sells[n];
            for(int j = 0;j<2500;j++)
                GetMerge(j);
            for(int j = 0;j<2500;j++)
            {
                if(GetMerge(j)==n)
                {
                    merges[j] = -1;
                    sells[j]="";
                }
            }
            sells[(r-1)*50+c-1] = val;
        }
        else if(com=="PRINT")
        {
            int r;
            int c;
            ss>>r>>c;
            int n = GetMerge((r-1)*50+c-1);
            if(sells[n].empty())
                answer.push_back("EMPTY");
            else
                answer.push_back(sells[n]);

        }
    }
    return answer;
}