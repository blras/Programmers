#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;
int SysToDec(int x, int sys)
{
    int a =0;
    int dec = 1;
    while(x>0)
    {
        int k = x%10;
        x = x/10;
        a+=k*dec;
        dec*=sys;
    }
    return a;
}
string DecToSys(int x,int sys)
{
    string s;
    if(x==0)
        return "0";
    while(x>0)
    {
        int k = x%sys;
        x = x/sys;
        s = to_string(k)+s;
    }
    return s;
}
int GetSys(int x,int y,int a,string cal)
{
    for(int i = 2;i<10;i++)
    {
        int dx = SysToDec(x,i);
        int dy = SysToDec(y,i);
        int da = SysToDec(a,i);
        int dxy = dx+dy;
        if(cal =="-")
            dxy =dx-dy;
        if(da==dxy)
            return i;
    }
    return 10;
}
vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    vector<int> vx ;
    int size = expressions.size();
    int system = 10;
    int lesys = 1;
    for(int i = 0;i<size;i++)
    {
        stringstream ss(expressions[i]);
        string x;
        string cal;
        string y;
        string equal;
        string a;
        ss>>x>>cal>>y>>equal>>a;
        if(a!="X")
        {
            if(system==10)
            {
                int ix = stoi(x);
                int iy = stoi(y);
                int ia = stoi(a);
                int dec =ix+iy;
                if(cal=="-")
                    dec = ix-iy;
                if(dec!=ia)
                    system = GetSys(ix,iy,ia,cal);
                else
                {
                    for(int j = 0;j<a.size();j++)
                    {
                        int k = a[j]-'0';
                        if(k>lesys)
                            lesys = k;
                    }
                }
            }
        }
        else
            vx.push_back(i);
        if(system==10)
        {
            for(int j = 0;j<x.size();j++)
            {
                int k = x[j]-'0';
                if(k>lesys)
                    lesys = k;
            }
            for(int j = 0;j<y.size();j++)
            {
                int k = y[j]-'0';
                if(k>lesys)
                    lesys = k;
            }
            if(lesys==8)
                system = 9;
        }
    }
    int vs = vx.size();
    if (lesys==8)
        system=9;
    for(int i = 0;i<vs;i++)
    {
        stringstream ss(expressions[vx[i]]);
        string x;
        string cal;
        string y;
        string equal;
        string a = "?";
        ss>>x>>cal>>y>>equal;
        int ix = stoi(x);
        int iy = stoi(y);
        if(system!=10)
        {
            int dx = SysToDec(ix,system);
            int dy = SysToDec(iy,system);
            int dec = dx+dy;
            if(cal=="-")
                dec = dx-dy;
            a = DecToSys(dec,system);
        }
        else
        {
            int dec = ix+iy;
            if(cal=="-")
                dec = ix-iy;
            a = to_string(dec);
            while(ix>0||iy>0)
            {
                int dx = ix%10;
                int dy = iy%10;
                ix = ix/10;
                iy = iy/10;
                int dd = dx+dy;
                if(cal=="-")
                    dd= dx-dy;
                if(dd>lesys||dd<0)
                {
                    a = "?";
                    break;
                }
            }
        }
        answer.push_back(x+" "+cal+" "+y+" "+equal+" "+a);
    }
    return answer;
}