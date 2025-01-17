#include <string>
#include <vector>
using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = -1;
    long long x1 = x;
    long long x2 = x;
    long long y1 = y;
    long long y2 = y;
    
    for(int i = queries.size()-1;i>=0;i--)
    {
        switch(queries[i][0])
        {
            case 0: y2+=queries[i][1];
                if(y2>=m)
                    y2 = m-1;
                if(y1!=0)
                    y1+=queries[i][1];
                if(y1>=m) 
                    return 0;
                break;
            case 1: y1-=queries[i][1];
                if(y1<0)
                    y1=0;
                if(y2!=m-1)
                    y2-=queries[i][1];
                if(y2<0)
                    return 0;
                break;
            case 2: x2 += queries[i][1];
                if(x2>=n)
                    x2 =n-1;
                if(x1!=0)
                    x1+=queries[i][1];
                if(x1>=n)
                    return 0;
                break;
            case 3: x1 -= queries[i][1];
                if(x1<0)
                    x1 = 0;
                if(x2!=n-1)
                    x2-= queries[i][1];
                if(x2<0)
                    return 0;
                break;
        }
    }
    long long dx = x2-x1+1;
    long long dy = y2-y1+1;
    answer =dx*dy;
    return answer;
}