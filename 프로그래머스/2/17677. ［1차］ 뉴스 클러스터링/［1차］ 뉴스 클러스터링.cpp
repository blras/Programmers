#include <string>
#include <cctype>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string str1, string str2) 
{
    int answer = 0;
    vector<string> j1;
    vector<string> j2;
    int tol = 'A'-'a';
    for(int i = 1;i<str1.size();i++)
    {
        string temp;
        if(isalpha(str1[i-1])&&isalpha(str1[i]))
        {
            char a = str1[i-1];
            char b = str1[i];
            if(isupper(a))
                a= tolower(a);
            if(isupper(b))
                b=tolower(b);
            temp.push_back(a);
            temp.push_back(b);
            j1.push_back(temp);
        }
    }
        for(int i = 1;i<str2.size();i++)
    {
         string temp;
        if(isalpha(str2[i-1])&&isalpha(str2[i]))
        {
            char a = str2[i-1];
            char b = str2[i];
            if(isupper(a))
                a= tolower(a);
            if(isupper(b))
                b=tolower(b);
            temp.push_back(a);
            temp.push_back(b);
            j2.push_back(temp);
        }
    }
    if(j1.size()==0&&j2.size()==0)
    {
        return 65536;
    }
    vector<bool> b1 (j1.size(),true);
    vector<bool> b2 (j2.size(),true);
    int n = 0;
    double u = 0;
    for(int i = 0;i<j1.size();i++)
    {
        if(b1[i])
        {
            for(int j = 0;j<j2.size();j++)
            {
                if(b2[j])
                {
                    if(j1[i]==j2[j]&&b1[i]&&b2[j])
                    {
                        n++;
                        b1[i] = false;
                        b2[j] = false;
                    }   
                }
            }
        }
    }
    u = j1.size()+j2.size()-n;
    long double d = (n/u) * 65536;
    answer = d;
    return answer;
}