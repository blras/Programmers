#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
bool IsRight(string p)
{
    string s = p;
    stack<char> sta;
    for(int i = 0;i<s.size();i++)
    {
        if(s[i]=='(')
            sta.push(s[i]);
        else if(s[i]==')')
        {
            if(sta.size()>0)
                sta.pop();
            else
                return false;
        }
    }
    return sta.empty();
}
int divided(string s)
{
    stack<char>sta;
    char c = s[0];
    for(int i = 0;i<s.size();i++)
    {
        if(s[i]==c)
            sta.push(c);
        else
        {
            if(sta.size()>0)
                sta.pop();
            else
                return i;
        }  
    }
    return s.size();
}
string reverse(string s)
{
    string temp;
    for(int i = 1; i <s.size()-1; i++)
    {
        if(s[i] == '(')
            temp.push_back(')');
        else
            temp.push_back('(');
    }
    return temp;
}
string con(string w)
{
    if(w.size()==0)
        return w;
    string s;
    /*int div = divided(w);
    string u =w.substr(0,div);
    if(div<w.size())
        v =w.substr(div);*/
    string u = "";
    string v = "";
    int l=0;
    int r=0;
    
    for(int i = 0;i<w.size();i++)
    {
        if(w[i] == '(')
            l++;
        else
            r++;
        if(l==r)
        {
            u =w.substr(0,i+1);
            v =w.substr(i+1);
            break;
        }
    }
    if(IsRight(u))
        s = u+con(v);
    else
        s = "(" +con(v) + ")" + reverse(u);
    return s;
}
string solution(string p) {
    string answer = "";
    answer = con(p);
    return answer;
}