#include<bits/stdc++.h>
#include<vector>
using namespace std;

char most_occured(string s, vector<int> &v)
{
    int n = s.length();
    int k = 0;
    int maxm = 0;
   // cout<<v.size()<<" ";
    while(n--)
    {
        int a = s[k];
        //cout<<" * "<<a<<"*";
        v[a-65]=v[a-65]+1;
       //cout<<" * "<<v[a-65]<<"-*";
        if(v[a-65] > maxm)
            maxm = k;
        k++;
    }
    //cout<<maxm<<"-   ";
return s[maxm];
}

int main()
{
    string msg = "AMARRAO";
    string ct = "COCTTCQ";
    int n1 = msg.length();
    int n2 = ct.length();
    vector<int> v1(26,0);
    vector<int> v2(26,0);
    char org = most_occured(msg,v1);
    char cip = most_occured(ct,v2);
    cout<<"Original Message:"<<msg<<endl<<endl;
    cout<<"Cipher Text:"<<ct<<endl<<endl;
    cout<<org<<" is converted to "<<cip<<endl;

    return 0;
}
