#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>


using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string,string> db;
    

    for (int i = 0; i < record.size(); i++)
    {
        vector<string> str;
        istringstream is(record[i]);
        string s;

        while (getline(is, s, ' '))
        {
            str.push_back(s);
        }
        if (str[0] == "Enter")
        {
            if (!db.empty() && db.find(str[1])!=db.end())
            {
                db[str[1]] = str[2];
            }
            else { db.insert(pair<string, string>(str[1], str[2])); }
        }
        else if (!db.empty() && str[0] == "Change")
        {
            db[str[1]] = str[2];
        }
    }
    for (int i = 0; i < record.size(); i++)
    {
        vector<string> str;
        istringstream is(record[i]);
        string s;

        while (getline(is, s, ' '))
        {
            str.push_back(s);
        }
        if (!db.empty() && str[0] == "Enter")
        {
            string s =db[str[1]]+ "님이 들어왔습니다.";
            answer.push_back(s);
        }
        else if (!db.empty() && str[0] == "Leave")
        {
            string s = db[str[1]] + "님이 나갔습니다.";
            answer.push_back(s);
        }
    }
    return answer;
}