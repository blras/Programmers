#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct file{
    string HEAD;
    int num;
    int idx;
};
bool Compares(file f1,file f2)
{

    if(f1.HEAD==f2.HEAD)
    {
        if(f1.num==f2.num)
            return f1.idx<f2.idx;
        return f1.num<f2.num;
    }
    else 
        return f1.HEAD<f2.HEAD;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    int size = files.size();
    vector<file> v;
    for(int i = 0;i<files.size();i++)
    {
        bool h;
        string num;
        file f;
        vector<int> idx;
        int temp =-1;
        for(int j =0;j<files[i].size();j++)
        {
            if((files[i][j]<'0'||files[i][j]>'9'))
            {
                if(!num.empty())
                    break;
                f.HEAD+=tolower(files[i][j]);
            }
            if(files[i][j]>='0'&&files[i][j]<='9')
                num+=files[i][j];
        }
        f.idx = i;
        f.num = stoi(num);
        v.push_back(f);
    }
    sort(v.begin(),v.end(),Compares);
    for(int i = 0;i<size;i++)
    {
        answer.push_back(files[v[i].idx]);
    }
    return answer;
}