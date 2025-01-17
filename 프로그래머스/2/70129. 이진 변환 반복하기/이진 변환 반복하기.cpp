#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string str = s;
    int count = 0;
    int delzero = 0;
    while(str != "1")
    {
        count++;
        string temp;
        for(int i = 0;i<str.size();i++)
        {
            if(str[i]=='0')
                delzero++;
            else
                temp.push_back(str[i]);
        }
        int size =temp.size();
        string bi;
        while(size>0)
        {
            int k = size%2;
            size = size/2;
            char c = k+'0';
            bi.push_back(c);
        }
        str = bi;
    }
    answer.push_back(count);
    answer.push_back(delzero);
    return answer;
}