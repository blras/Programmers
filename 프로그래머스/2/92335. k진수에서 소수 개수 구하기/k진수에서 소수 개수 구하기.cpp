#include <string>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;
bool isprime(long long ll)
{
    if(ll==1)
        return false;
    long long sl = sqrt(ll);
    for(long long i = 2;i<=sl;i++)
    {
        if(ll%i==0)
            return false;
    }
    return true;
}
int solution(int n, int k) {
    long long answer = 0;
    string str;
    int temp  =n;
    while(temp!=0)
    {
        int x = temp%k;
        temp = temp/k;
        char c = x+'0';
        str.insert(str.begin(),c);
    }
    istringstream iss(str);
    string buf;
    while(getline(iss,buf,'0'))
    {
        long long ll;
        if(buf.size()==0)
            continue;
        else
            ll = stoll(buf);
        if(isprime(ll))
            answer++;
    }
    return answer;
}