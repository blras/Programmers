#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> memo;
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer= {0,0};
    int size = arr.size();
    vector<int> v (size,0);
    memo = vector<vector<int>> (size,v);
    int n = size;
    
    while(n>0)
    {
        int w = 0;
        int h = 0;
        while(h<size)
        {
            if(memo[h][w]!=0)
            {
                w+=memo[h][w];
                if(w>=size)
                {
                    w=0;
                    h+=n;
                }
                continue;
            }
            bool b = true;
            int temp = arr[h][w];
            for(int i = 0;i<n;i++)
            {
                for(int j = i;j<n;j++)
                {
                    if(temp!=arr[h+i][w+j]||temp!=arr[h+j][w+i])
                    {
                        b=false;
                        break;
                    }
                }
                if(!b)
                    break;
                //tm[h+i][w] = n;
            }
            if(b)
            {
                for(int i = 0;i<n;i++)
                    memo[h+i][w] = n;
                answer[temp]++;
            }
            w+=n;
            if(w==size)
            {
                w=0;
                h+=n;
            }
        }
        n=n/2;
    }
    return answer;
}