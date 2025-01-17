#include <string>
#include <vector>

using namespace std;

struct node 
{
       
};
    
string func(int n)
{
    string a;
    if(n==1)
    {
        a = "1";
    }
    else if(n==2)
    {
        a="2";
    }
    else if(n==3)
    {
        a="4";
    }
    else
    {
        int r = n%3;
        int k = n/3;
        if(r == 0)
        {
            a = func(k-1) + func(3);
        }
        else
        {
            a = func(k) + func(r);
        }
    }
    return a;
}
string solution(int n) {
    string answer = "";
    int f = 0;
    int b = 0;
    
    answer = func(n);
    return answer;
}