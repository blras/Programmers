#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    N  = A.size();
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int a = 0;
    int b = 0;
    while(a<N&&b<N)
    {
        if(A[a]<B[b])
        {
            answer++;
            a++;
            b++;
        }
        else
            b++;
    }
    return answer;
}