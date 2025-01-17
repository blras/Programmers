#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;
vector<int> solution(vector<int> fees, vector<string> records) 
{
    vector<int> answer;
    unordered_map<string,int> parking;
    map<string,int> cost;
    for(int i = 0;i<records.size();i++)
    {
        string str = records[i].substr(0,2);
        int k = stoi(str);
        str = records[i].substr(3,2);
        k =k*60 + stoi(str);
        str = records[i].substr(6,4);
        string inout = records[i].substr(11);
        if(inout=="IN")
        {
            parking.insert({str,k});
            if(cost.count(str)==0)
                cost.insert({str,0});
        }
        else
        {
            auto temp = parking.find(str);
            int in = temp->second;
            k -= in;
            auto car = cost.find(str);
            car->second +=k;
            parking.erase(str);
        }
    }
    if(parking.size()>0)
    {
        for(auto iter:parking)
        {
            int k = 1439;
            int in = iter.second;
            k -= in;
            auto car = cost.find(iter.first);
            car->second += k;
        }
    }

    for(auto iter:cost)
    {
        int k = iter.second;
        int fee = fees[1];
        if(k>fees[0])
        {
            k -=fees[0];
            int exfee = k/fees[2];
            if(k%fees[2]>0)
                exfee++;
            fee += exfee*fees[3];
        }
        answer.push_back(fee);
    }
    
    return answer;
}