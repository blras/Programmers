#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<long long> FXY(double a1,double b1,double c1,double a2, double b2, double c2)
{
    vector<long long> v;
    long double x;
    long double y;
    if( a1*b2-b1*a2 !=0 )
    {   
        x = (b1*c2-c1*b2)/(a1*b2-b1*a2);
        y = (c1*a2-a1*c2)/(a1*b2-b1*a2);
    }
    else
    {
        return v;
    }
    long long n = x;
    long long m = y;
    if(x==n&&y==m)
    {
        v.push_back(x);
        v.push_back(y);
    }
    
    return v;
}
vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<vector<long long>> inters;
    vector<bool>weight (1024,false);
    vector<vector<bool>> dots (1024,weight);
    long long uh;
    long long dh;
    long long lw;
    long long rw;
    for(int i = 0;i<line.size();i++)
    {
        for(int j = i+1;j<line.size();j++)
        {
            vector<long long> v;
            v= FXY(line[i][0],line[i][1],line[i][2],line[j][0],line[j][1],line[j][2]);
            if(v.size()>0)
            {
                if(inters.size()==0)
                {
                    uh = v[1];
                    dh = v[1];
                    rw = v[0];
                    lw = v[0];
                }
                else
                {
                    if(v[1]>uh)
                    {uh = v[1];}
                    if(v[1]<dh)
                    {dh = v[1];}
                    if(v[0]>lw)
                    {lw = v[0];}
                    if(v[0]<rw)
                    {rw = v[0];}
                }
                inters.push_back(v);
            }
        }
    }
    int mh = uh - dh;
    int mw = lw - rw;
    for(int i = 0;i<inters.size();i++)
    {
        vector<long long> v = inters[i];
        int x = v[0] -rw;
        int y = v[1] -dh;
        if(1024>x&&x>=0&&1024>y&&y>=0)
        {
            dots[y][x]=true;
        }   
    }
    for(int i =mh; i>=0;i--)
    {
        string str = "";
        for(int j =0;j<=mw;j++)
        {
            if(dots[i][j])
                str.push_back('*');
            else
                str.push_back('.');
        }
        answer.push_back(str);
    }
    return answer;
}