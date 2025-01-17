#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    vector<vector<int>> cosum(1001,vector<int>(1001,0));
    vector<vector<int>> table =board;
    int row = board.size();
    int col = board[0].size();
    
    for(int i = 0;i<skill.size();i++)
    {
        int temp=skill[i][5];
        if(skill[i][0]==1)
            temp = temp*-1;
        int x1 = skill[i][1];
        int x2 = skill[i][3];
        int y1 = skill[i][2];
        int y2 = skill[i][4];
        cosum[x1][y1] += temp;
        cosum[x2+1][y2+1] += temp;
        cosum[x1][y2+1] -= temp;
        cosum[x2+1][y1] -= temp;  
    }
    for(int i = 0;i<row;i++)
        for(int j=0;j<col;j++)
            cosum[i][j+1] += cosum[i][j];
    for(int i = 0;i<row;i++)
        for(int j=0;j<col;j++)
            cosum[j+1][i] += cosum[j][i];
    for(int i = 0;i<row;i++)
        for(int j=0;j<col;j++)
            if(table[i][j]+cosum[i][j] >0)
                answer++;
    return answer;
}