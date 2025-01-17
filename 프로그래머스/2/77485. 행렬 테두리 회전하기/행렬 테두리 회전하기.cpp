#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> table;
    
    for(int i = 0;i<rows;i++)
    {
        vector<int> v;
        table.push_back(v);
        for(int j = 0; j<columns;j++)
        {
            table[i].push_back(i*columns+(j+1));
        }
    }
    for(int i = 0;i<queries.size();i++)
    {
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];
        int dx = x2-x1;
        int dy = y2-y1;
        int temp = 0;
        int k = rows*columns +1;
        for(int i = x1;i<=x2;i++)
        {
            for(int j = y1; j<=y2;j++)
            {
                if(i==x1&&j==y1)
                {
                    if(table[i-1][j-1]<k)
                        k = table[i-1][j-1];
                    temp = table[i-1][j];
                    table[i-1][j] = table[i-1][j-1];
                }
                else if(i==x1&&j!=y2)
                {
                    if(temp<k)
                        k = temp;
                    int tem = table[i-1][j];
                    table[i-1][j]= temp;
                    temp = tem;
                }
                else if(j==y1&&i!=x1)
                {
                    if(table[i-1][j-1]<k)
                        k = table[i-1][j-1];
                    table[i-2][j-1] = table[i-1][j-1];
                }
                else if(i==x2&&j==y2)
                {
                    if(temp<k)
                        k = temp;
                    table[i-1][j-2]=temp;
                }
                else if(i==x2&&j!=y1)
                {
                    if(table[i-1][j-1]<k)
                        k = table[i-1][j-1];
                    table[i-1][j-2]=table[i-1][j-1];
                }
                else if(j==y2&&i!=x2)
                {
                    if(temp<k)
                        k = temp;
                    int tem = table[i][j-1];
                    table[i][j-1] = temp;
                    temp =tem;
                }
            }
        }
        answer.push_back(k);
    }
    return answer;
}