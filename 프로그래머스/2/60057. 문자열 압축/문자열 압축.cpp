#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(string s) {
    int answer = 0;
    int len = s.size();
    

    for (int i = 2; i <= s.size()/2; i++)
    {
        string compre;
        deque<string> dq;
        int c = 0;
        int n = 0;

        while (c < s.size()-i)
        {
            string com;

            for (int j = 0; j < i; j++)
            {
                com = com + s[c+j];
            }
            if (dq.empty())
            {
                dq.push_back(com);
            }
            if (dq.back() == com)
            {
                n++;
            }
            else if(dq.back() != com)
            {
                if (n > 1)
                {
                    string com2 = to_string(n)+ dq.back();
                    dq.pop_back();
                    dq.push_back(com2);
                }
                n = 1;
                dq.push_back(com);
            }
            c += i;
        }
        for (int j = c; j < s.size(); j++)
        {
            compre = compre + s[j];
            if (compre == dq.back())
            {
                n++;
                compre.clear();
            }
        }
        if (n > 1)
        {
            string com2 = to_string(n) + dq.back();
            dq.pop_back();
            dq.push_back(com2);
        }
        while (!dq.empty())
        {
            compre =  dq.back() + compre ;
            dq.pop_back();
        }
        if (compre.size() < len)
            len = compre.size();
    }
    string temp;
    int n = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (temp.empty())
            temp.push_back(s[i]);
        if (temp.back() == s[i])
            n++;
        else 
        {
            if (n > 1)
            {
                string com1 = to_string(n) + temp.back();
                temp.pop_back();
                temp = temp + com1;
                n = 1;
            }
            temp.push_back(s[i]);
        }
    }
    if (n > 1)
    {
        string com1 = to_string(n) + temp.back();
        temp.pop_back();
        temp = temp + com1;
    }

    len = temp.size() < len ? temp.size() : len;

    answer = len;
    return answer;
}