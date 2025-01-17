#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    int turn = t;
    int num = -1;
    int player = 1;
    string count = "";
    while(turn>0)
    {
        if(count.empty())
        {
            num++;
            int a = num;
            if(a==0)
                count="0";
            while(a>0)
            {
                char c = a%n +'0';
                if(a%n>=10)
                    c = 'A'-10+a%n;
                count = c+count;
                a = a/n;
            }
        }
        if(player == p)
        {
            char c =count[0];
            answer+=c;
            turn-=1;
        }
        count = count.substr(1);
        if(player<m)
            player++;
        else
            player = 1;
    }
    return answer;
}