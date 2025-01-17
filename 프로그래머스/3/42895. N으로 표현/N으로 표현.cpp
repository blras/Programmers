#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    vector<unordered_set<int>> dyn;
    unordered_set<int> s;

    if (N == number)
    {
        return 1;
    }

    int NN = 0;
    for (int i = 0; i < 8; i++)
    {
        unordered_set<int> s;
        dyn.push_back(s);

        NN = NN * 10 + N;

        dyn[i].insert(NN);
    }


    for (int i = 1; i < 8; i++)
    {
        for(int j = 0;j<i;j++)
        { 
            for (auto oper1 : dyn[j])
            {
                for (auto oper2 : dyn[i - j-1])
                {
                    dyn[i].insert(oper1 + oper2);
                    dyn[i].insert(oper1 - oper2);
                    dyn[i].insert(oper1 * oper2);
                    if (oper2 != 0)
                        dyn[i].insert(oper1 / oper2);
                }
            }
        }
        if (dyn[i].find(number) != dyn[i].end())
        {
            answer = i + 1;
            break;
        }
    }
    return answer;
}