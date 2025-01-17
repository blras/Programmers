#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
struct node{
    node *next;
    long long num;
    char cal;
};
long long calculation(long long a,long long b, char c)
{
    long long result =0;
    switch(c)
    {
        case '+': result = a+b;break;
        case '-': result = a-b;break;
        case '*': result = a*b;break;
    }
    return result;
}
long long calculating(vector<int>nums,vector<char> sign, string o)
{
    long long sum =0;
    node *root = new node;
    root->num = nums[0];
    root->cal = sign[0];
    node *temp = root;
    for(int i = 1;i<sign.size();i++)
    {
        node *n = new node;
        n->num = nums[i];
        n->cal = sign[i];
        temp->next = n;
        temp = n;
    }
    node *last = new node;
    last->num = nums[nums.size()-1];
    temp->next = last;
    last->next = nullptr;
    for(int i =0;i<o.size();i++)
    {
        temp = root;
        while(temp!=nullptr)
        {
            if(temp->cal == o[i])
            {
                temp->num = calculation(temp->num,temp->next->num,o[i]);
                temp->cal = temp->next->cal;
                if(temp->next->next !=nullptr)
                    temp->next =temp->next->next;
                else
                    temp->next = nullptr;
            }
            else
                temp = temp->next;
        }
    }
    sum = root->num;
    if(sum<0)
        sum = sum *(-1);
    return sum;
}
long long solution(string expression) {
    long long answer = 0;
    vector<int> nums;
    vector<char> cal;
    vector<string> order = {"+-*","+*-","-+*","-*+","*-+","*+-"};
    string temp;
    long long sum = 0;
    for(int i = 0;i<expression.size();i++)
    {
        if(isdigit(expression[i]))
        {
            temp.push_back(expression[i]);
        }
        else if(temp.size()>0)
        {
            int num = stoi(temp);
            nums.push_back(num);
            temp.clear();
            cal.push_back(expression[i]);
        } 
    }
    if(temp.size()>0)
    {
        int num = stoi(temp);
        nums.push_back(num);
        temp.clear();
    }
    
    for(int i = 0;i<6;i++)
    {
        sum = calculating(nums,cal,order[i]);
        if(sum>answer)
            answer = sum;
    }
    return answer;
}