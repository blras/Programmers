#include <string>
#include <vector>
#include <iostream>
using namespace std;
int solution(string dirs) {
    int answer = 0;
    int x = 5;
    int y = 5;
    int size = dirs.size();
    vector<bool> b (4,false);
    vector<vector<bool>> Y (11,b);
    vector<vector<vector<bool>>> XY (11,Y);
    for(int i = 0;i<size;i++)
    {
        switch(dirs[i])
        {
            case 'U':
                if(y+1<=10)
                {    
                    int temp = y;
                    y+=1;
                    if(!XY[x][y][0])
                    {   
                        answer++;
                        XY[x][y][0]=true;
                        XY[x][temp][1]=true;
                    }
                }
                    break;
            case 'D':
                if(y-1>=0)
                {    
                    int temp = y;
                    y-=1;
                    if(!XY[x][y][1])
                    {   
                        answer++;
                        XY[x][y][1]=true;
                        XY[x][temp][0]=true;
                    }
                }
                break;  
            case 'R':
                if(x+1<=10)
                {    
                    int temp = x;
                    x+=1;
                    if(!XY[x][y][2])
                    {   
                        answer++;
                        XY[x][y][2]=true;
                        XY[temp][y][3]=true;
                    }
                }
                break;
            case 'L':
                if(x-1>=0)
                {    
                    int temp = x;
                    x-=1;
                    if(!XY[x][y][3])
                    {   
                        answer++;
                        XY[x][y][3]=true;
                        XY[temp][y][2]=true;
                    }
                }
                break;
        }
        cout<<x-5<<","<<y-5<<"|";
    }
    
    return answer;
}