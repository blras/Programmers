#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;
struct node{
    node* left = nullptr;
    node* right = nullptr;
    node* pre = nullptr;
    bool hasnum;
    int num;
};
void Insert(node *n, int x)
{
    if(n->num>x)
    {
        if(n->left==nullptr)
        {
            node *l =new node;
            l->left = nullptr;
            l->right = nullptr;
            l->num = x;
            n->left = l;
            l->pre = n;
            l->hasnum = true;
        }
        else
            Insert(n->left,x);
    }
    else
    {
        if(n->right==nullptr)
        {
            node *r =new node;
            r->left = nullptr;
            r->right = nullptr;
            r->num = x;
            n->right = r;
            r->pre = n;
            r->hasnum = true;
        }
        else
            Insert(n->right,x);
    }
}
node* Delm(node *n)
{
    if(n->left==nullptr)
    {
        if(n->right!=nullptr)
        {
            if(n->pre!=nullptr)
            {
                n->pre->left = n->right;
                n->right->pre = n->pre;
            }
            else
            {
                n = n->right;
                n->pre = nullptr;
                return n;
            }
        }
        else
        {
            if(n->pre!=nullptr)
                n->pre->left = nullptr;
            else
                n->hasnum=false;
        }
    }
    else
        Delm(n->left);
    return n;
}
node* DelM(node *n)
{
    if(n->right==nullptr)
    {
        if(n->left!=nullptr)
        {
            if(n->pre!=nullptr)
            {
                n->pre->right = n->left;
                n->left->pre = n->pre;
            }
            else
            {
                n = n->left;
                n->pre = nullptr;
                return n;
            }
        }
        else
        {
            if(n->pre!=nullptr)
                n->pre->right = nullptr;
            else
                n->hasnum=false;
        }
    }
    else
        DelM(n->right);
    return n;
}
int GetM(node* n)
{
    if(n->right==nullptr)
        return n->num;
    else
        return GetM(n->right);
}
int Getm(node* n)
{
    if(n->left==nullptr)
        return n->num;
    else
        return Getm(n->left);
}
void que(node *n)
{
    if(n->left!=nullptr)
        que(n->left);
    
    cout<<n->num<<",";
    
    if(n->right!=nullptr)
        que(n->right);
}
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    node* root = new node;
    root->pre = nullptr;
    root->left = nullptr;
    root->right = nullptr;
    root->hasnum = false;
    for(int i = 0;i<operations.size();i++)
    {
        if(operations[i][0]=='I')
        {
            string str = operations[i].substr(2,operations[i].size()-1);
            int temp = stoi(str);
            if(!root->hasnum)
            {
                root->num = temp;
                root->hasnum=true;
            }
            else
                Insert(root,temp);
        }
        else if(root->hasnum)
        {
            if(operations[i][2]=='1')
                root = DelM(root);
            else
                root = Delm(root);
        }
    }
    if(!root->hasnum)
        answer = {0,0};
    else
        answer = {GetM(root),Getm(root)};
    return answer;
}