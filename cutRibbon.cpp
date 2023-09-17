#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(int n,int a,int b,int c,vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(n<0){
        return -1e9+7;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int x=solve(n-a,a,b,c,dp);
    int y=solve(n-b,a,b,c,dp);
    int z=solve(n-c,a,b,c,dp);
    return dp[n]= 1+max(x,max(y,z));
}
int main(){
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    vector<int>dp(n+1,-1);
    int result=solve(n,a,b,c,dp);
    cout<<result;
    return 0;
}