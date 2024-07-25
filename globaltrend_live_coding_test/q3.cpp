// Problem Statement
// Write a function to solve the 0/1 Knapsack problem using dynamic programming.


#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int knapsack(vector<vector<int>> &v,int cap,int i,vector<vector<int>> &dp){
    if(i>=v.size()) return 0;
    if(dp[i][cap]!=-1) return dp[i][cap];
    int take=0;
    if(cap>=v[i][0]){
        take=v[i][1]+knapsack(v,cap-v[i][0],i+1,dp);
    }
    return dp[i][cap]=max(take,knapsack(v,cap,i+1,dp));
}
int main() {
    // Write C++ code here
   vector<vector<int>> v;
   int items=0;
   cout<<"Enter number of items : "<<endl;
   cin>>items;
   cout<<"enter wt and val of each item : "<<endl;
   for(int i=0;i<items;i++){
       int wt;
       int val;
       cin>>wt>>val;
       v.push_back({wt,val});
   }
   int cap=0;
   cout<<"enter capacity : "<<endl;
   cin>>cap;
   vector<vector<int>> dp(items+1,vector<int>(cap+1,-1));
   cout<<"Maximum value that can be obtained: "<<knapsack(v,cap,0,dp);
   
    return 0;
}