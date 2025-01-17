#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int>F;
vector<int>B;
struct node{
    int num;
    int x;
    node *pra;
    node *left;
    node *right;
};
void Nodeinsert(node *n,pair<int,int> p)
{
    if(n->x<p.first)
    {
        if(n->right==nullptr)
        {
            node *r = new node;
            r->x = p.first;
            r->num = p.second;
            r->pra = n;
            r->left = nullptr;
            r->right = nullptr;
            n->right = r;
        }
        else
            Nodeinsert(n->right,p);
        }
    else if (n->x>p.first)
    {
        if(n->left==nullptr)
        {
            node *l = new node;
            l->x = p.first;
            l->num = p.second;
            l->pra = n;
            l->left = nullptr;
            l->right = nullptr;
            n->left = l;
        }
        else
            Nodeinsert(n->left,p);
    }
}
void NodeSerch(node *n)
{
    F.push_back(n->num);
    if(n->left!=nullptr)
        NodeSerch(n->left);
    if(n->right!=nullptr)
        NodeSerch(n->right);
    B.push_back(n->num);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<pair<int,int>> vp;
    int size = nodeinfo.size();
    for(int i = 0;i<size;i++)
        vp.push_back({nodeinfo[i][1],i+1});
    sort(vp.begin(),vp.end(),greater());
    node *root = new node;
    root->num = vp[0].second;
    root->x = nodeinfo[vp[0].second-1][0];
    root->pra = nullptr;
    root->left = nullptr;
    root->right = nullptr;
    
    for(int i = 1;i<size;i++)
    {
        pair<int,int> p = {nodeinfo[vp[i].second-1][0],vp[i].second};
        Nodeinsert(root,p);
    }
    NodeSerch(root);
    answer.push_back(F);
    answer.push_back(B);
    return answer;
}