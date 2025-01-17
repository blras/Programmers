#include <string>
#include <vector>
#include <iostream>

using namespace std;
struct node
{  
    public:
    bool ok;
    vector<bool> data;
    vector<string> comp;
    string req;
};

void compare( char c,node *n)
{
    bool flag = true;
    for(int i =0;i<n->comp.size();i++)
    {
        switch(n->comp[i][1])
        {
                case'=':
                if(n->comp[i][2]=='0')
                {
                    if(c!=n->comp[i][0])
                    {
                        flag = false;
                    }
                    n->comp.erase(n->comp.begin()+i);
                    i--;
                }
                else
                {
                    if(c==n->comp[i][0])
                    {
                        flag=false;
                    }
                    else
                    {
                        n->comp[i][2]--;
                    }
                }
                    break;
                case'>':
                if(c==n->comp[i][0])
                {
                    flag=false;
                }
                if(n->comp[i][2]=='0')
                {
                    n->comp.erase(n->comp.begin()+i);
                    i--; 
                }
                else
                {
                    n->comp[i][2]--;
                }
                break;
                case'<':
                if(n->comp[i][2]<='1')
                {
                    if(c!=n->comp[i][0])
                    {
                        flag=false;
                    }
                    n->comp.erase(n->comp.begin()+i);
                    i--;
                }
                else
                {
                    if(c==n->comp[i][0])
                    {
                        n->comp.erase(n->comp.begin()+i);
                        i--;
                    }
                    else
                    {
                        n->comp[i][2]--;
                    }
                }break;
        }
    }
    if(flag==false)
    {
        n->ok=false;
    }
    else
    {
        n->ok=true;
    }
    return;
}
void dataRead( char c, vector<string> data,node *n)
{
    for(int i =0;i<data.size();i++)
    {
        if(n->data[i]==false)
        {
            if(c==data[i][0])
            {
                n->data[i]=true;
                string str;
                str.push_back(data[i][2]);
                str.push_back(data[i][3]);
                str.push_back(data[i][4]);
                n->comp.push_back(str);
                
            }
            if(c==data[i][2])
            {
                n->data[i]=true;
                string str;
                str.push_back(data[i][0]);
                str.push_back(data[i][3]);
                str.push_back(data[i][4]);
                n->comp.push_back(str);
            }
        }
    }
    return;
}
int setarr(string v,int count,vector<string> data,node *nd)
{
    node *nnd = new node;
    nnd->data = nd->data;
    nnd->comp = nd->comp;
    nnd->ok=false;
    for(int i = 0;i<v.size();i++)
    {
        compare(v[i],nnd);
        dataRead(v[i],data,nnd);
        if(nnd->ok)
        {
            string temp = v;
            nnd->req.push_back(v[i]);
            temp.erase(temp.begin()+i);
            if (temp.size() == 0)
            {
                count++;
            }
            count = setarr(temp,count, data,nnd);
        }
        nnd->data = nd->data;
        nnd->comp = nd->comp;
    }
    return count;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string v = "ACFJMNRT";
    
    node *root = new node;
    for(int i = 0;i<n;i++)
    {
        root->data.push_back(false);
    }
    answer = setarr(v,0,data,root);
    return answer;
}