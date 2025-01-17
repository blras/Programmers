#include <string>
#include <vector>
using namespace std;
string Up(string s)
{
    int size = s.size();
    switch (s[size-1])
    {
        case 'A': s[size-1] = 'E';break;
        case 'E': s[size-1] = 'I';break;
        case 'I': s[size-1] = 'O';break;
        case 'O': s[size-1] = 'U';break;
        case 'U': 
            s.pop_back();
            s = Up(s);
            break;
    }
    return s;
}
int solution(string word) {
    int answer = 1;
    int size = 5;
    vector<string> words;
    string s = "A";
    
    while(s!=word)
    {
        if(s.size()<size)
            s.push_back('A');
        else
            s=Up(s);
        answer++;
    }
    return answer;
}