// https://leetcode.com/problems/climbing-stairs/

#include<bits/stdc++.h>
using namespace std;
    
int f(int idx, vector<int> &dp){
    if(idx == 0) return 1;
    if(idx == 1) return 1;
        
        // 2
    if(dp[idx] != -1){
        return dp[idx];
    }
        
     int left = f(idx - 1, dp);
    int right = f(idx - 2, dp);
        // 3
     return dp[idx] = left + right;
}
    
int climbStairs_memo(int n) {  // tc -> o(n) // sc -> o(n) + o(n)
        // 1 
     vector<int> dp(n+1, -1);
    return f(n, dp);
}
int climbStairs_tebu(int n) {  // // tc -> o(n) // sc -> o(n) 
      vector<int>dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            int left=dp[i-1];
            int right =dp[i-2];
            dp[i]=left+right;
        }
        return dp[n];

}
int climbStairs_space_opt(int n) {  // tc -> o(n) // sc ->  o(1)
      
        int prev2= 1;
        int prev = 1;
        for(int i=2;i<=n;i++)
        {
            int left = prev;
            int right = prev2;
            int curr_i= left + right;
             prev2 = prev;
            prev = curr_i;
        }
        return prev;

}
int main(){
    int n;
    cin >> n;
    //cout << climbStairs_memo(n);
    // cout << climbStairs_tebu(n);
    cout << climbStairs_space_opt(n);
}