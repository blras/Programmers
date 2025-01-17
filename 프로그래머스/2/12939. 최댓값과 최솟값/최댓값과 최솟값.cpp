#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int temp = 0;
    bool pos = true;
    int max = -2147483645;
    int min = 2147483646;
    for(int i = 0;i<s.size();i++)
    {
        if(isdigit(s[i]))
        {
            int k = s[i]-'0';
            temp = temp*10 + k;
        }
        else if (s[i]=='-')
            pos = false;
        else if (s[i]==' ')
        {
            if(!pos)
                temp *=-1;
            if(temp>max)
                max = temp;
            if(temp<min)
                min = temp;
            pos = true;
            temp = 0;
        }
    }
    if(!pos)
        temp *=-1;
    if(temp>max)
        max = temp;
    if(temp<min)
        min = temp;
    string ma = to_string(max);
    string mi = to_string(min);
    answer = answer+mi+" "+ma;
    return answer;
}