#include <string>
#include <vector>
#include <sstream>


using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<int>start;
    vector<int>end;

    for (int i = 0; i < lines.size(); i++)
    {
        vector<string> str;
        vector<string> clock;
        istringstream is(lines[i]);
        string temp;

        while (getline(is, temp, ' '))
        {
            str.push_back(temp);
        }
        
        istringstream iis (str[1]);

        while (getline(iis, temp, ':'))
        {
            clock.push_back(temp);
        }
        
        int h = stoi(clock[0]) * 60 * 60 * 1000;
        int m = stoi(clock[1]) * 60 * 1000;
        int s = stod(clock[2]) * 1000;
        end.push_back(h + m + s);

        str[2].pop_back();
        int process = stod(str[2]) * 1000;
        start.push_back(h + m + s - process + 1);
    }
    for (int i = 0; i < lines.size(); i++)
    {
        int close = end[i] + 1000;
        int count = 0;

        for (int j = 0; j < lines.size(); j++)
        {
            if (close >start[j]&&end[j]>=end[i])
            {
                count++;
            }
        }
        if (count > answer)
        {
            answer = count;
        }
    }
    return answer;
}