// Problem Statement
// Write a function to find the longest common subsequence of two given strings.


#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int longestCommonSubsequence(string &str1,string &str2,int i,int j,vector<vector<int>> &dp){
  if(i>=str1.size() or j>=str2.size()){
    return 0;
  }
  if(dp[i][j]!=-1) return dp[i][j];
  if(str1[i]==str2[j]){
    return dp[i][j]=1+longestCommonSubsequence(str1,str2,i+1,j+1,dp);
  }
  return dp[i][j]=max(longestCommonSubsequence(str1,str2,i+1,j,dp),longestCommonSubsequence(str1,str2,i,j+1,dp));
}



int main(){
  string str1;
  string str2;
  cout<<"Enter two strings"<<endl;
  cin>>str1>>str2;
  int n=str1.size();
  int m=str2.size();
  vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
  cout<<"longest common subsequence is of lenght : "<<longestCommonSubsequence(str1,str2,0,0,dp);
}