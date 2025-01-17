#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<string> b;
vector<vector<bool>> memo;
int height;
int width;
bool TwoTwo()
{
    bool temp = false;
    vector<vector<bool>> m = memo;
    for(int i = 0;i<height-1;i++)
    {
        for(int j = 1;j<width-1;j++)
        {
            
            char c = b[i][j];
            if(c=='0')
                continue;
            if(b[i+1][j]==c&&b[i][j+1]==c&&b[i+1][j+1]==c)
            {
                m[i][j]=true;
                m[i+1][j]=true;
                m[i][j+1]=true;
                m[i+1][j+1]=true;
                temp = true;
            }
            if (b[i+1][j]==c&&b[i][j-1]==c&&b[i+1][j-1]==c)
            {
                m[i][j]=true;
                m[i+1][j]=true;
                m[i][j-1]=true;
                m[i+1][j-1]=true;
                temp = true;
            }
        }
    }
    for(int i = 0;i<height;i++)
    {
        for(int j = 0;j<width;j++)
        {
            if(m[i][j])
                b[i][j]='0';
        }
    }
    return temp;
}
void Grav()
{
    for(int j = 0;j<width;j++)
    {
        int temp = 0;
        for(int i = height-1;i>=0;i--)
        {
            if(temp>0&&b[i][j]!='0')
            {
                b[temp][j] = b[i][j];
                temp-=1;
                b[i][j]='0';
            }
            else if(b[i][j]=='0')
            {
                if(temp<i)
                    temp = i;
            }
        }
    }
    return;
}
void Debug()
{
    for(int i = 0;i<height;i++)
    {
        for(int j = 0;j<width;j++)
            cout<<b[i][j]<<",";
        cout<<"\n";
    }
    cout<<"\n";
}
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    b = board;
    height = board.size();
    width = board[0].size();
    vector<bool> v (width,false);
    memo = vector<vector<bool>> (height,v); 
    bool temp = true;
    while(temp)
    {
        temp = TwoTwo();
        Grav();
    }
    for(int i = 0;i<height;i++)
        for(int j = 0;j<width;j++)
            if(b[i][j]=='0')
                answer++;
    return answer;
}