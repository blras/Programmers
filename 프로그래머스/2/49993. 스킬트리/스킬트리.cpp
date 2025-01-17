#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<bool> memo (30,false);
    for(int i = 0;i<skill.size();i++)
        memo[skill[i]-'A'] = true;
    for(int i = 0;i<skill_trees.size();i++)
    {
        bool able = true;
        int tree= 0;
        for(int j = 0;j<skill_trees[i].size();j++)
        {
            char temp = skill_trees[i][j];
            int tn = temp-'A';
            if(memo[tn]&&skill[tree]==temp)
                tree++;
            else if(memo[tn]&&skill[tree]!=temp)
            {
                able = false;
                break;
            }
        }
        if(able)
            answer++;
    }
    return answer;
}