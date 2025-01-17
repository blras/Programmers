#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool Upper = true;
    for(int i = 0;i<s.size();i++)
    {
        char c = s[i];
        if(isalpha(s[i])&&Upper)
        {
            c = toupper(c);
        }
        else if (s[i]==' ')
        {
            Upper = true;
            answer.push_back(c);
            continue;
        }
        else if(isalpha(s[i]))
            c = tolower(c);
        answer.push_back(c);
        Upper = false;
    }
    return answer;
}