#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    vector<string> songs;
    int len = 0;
    for(int i = 0;i<musicinfos.size();i++)
    {
        istringstream ss (musicinfos[i]);
        vector<string> v;
        string sub;
        while(getline(ss,sub,','))
            v.push_back(sub);
        int time = 0;
        for(int j = 0;j<v[0].size();j++)
        {
            if(j==2)
                continue;
            int t0 = v[0][j] - '0';
            int t1 = v[1][j] - '0';
            int t = t1-t0;
            if(j==0)
                t*=600;
            else if (j==1)
                t*=60;
            else if (j==3)
                t*=10;
            time+=t;
        }
        if(time<=len)
            continue;
        string mel;
        int k =0;
        for(int j = 0;j<time;j++)
        {
            if(k>=v[3].size())
                k-=v[3].size();
            mel.push_back(v[3][k]);
            k++;
            if(v[3][k]=='#')
            {
                mel.push_back(v[3][k]);
                k++;
            }
        }
        size_t pos= mel.find(m); 
        while(pos!=string::npos)
        {
            if(mel[pos+m.size()]=='#')
            {
                pos= mel.find(m,pos+m.size()+1);
                continue;
            }
            len = time;
            answer = v[2];
            break;
        }
    }
    return answer;
}