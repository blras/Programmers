#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    int i = 0;
    int size =order.size()+1;
    int count = 1;
    while(i<size)
    {
        if(order[i]==count)
        {
            answer++;
            i++;
            count++;
        }
        else if(!s.empty()&&s.top()==order[i])
        {
            answer++;
            i++;
            s.pop();
        }
        else
        {
            s.push(count);
            count++;
        }
        if(count>size)
            break;
    }
    return answer;
}