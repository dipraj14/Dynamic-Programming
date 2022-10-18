// https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?leftPanelTab=0
#include <bits/stdc++.h> 
using namespace std;
int helper(int idx,vector<int> &price, int n, vector<vector<int>> &dp){
    if(idx == 0){
        return n * price[0];
    }
    if(dp[idx][n] != -1) return dp[idx][n];
    int notPick = 0 + helper(idx - 1, price, n, dp);
    int pick = INT_MIN;
    int rodeLen = idx + 1;
    if(rodeLen <= n){
       pick = price[idx] + helper(idx , price , n - rodeLen, dp); 
    }
    
    return dp[idx][n] = max(pick , notPick);
}
int helper_tebu(vector<int> &price, int N){  // n = 5
    vector<vector<int>> dp(N , vector<int> (N + 1, 0));
    
    for(int i = 0; i<=N; i++){
        dp[0][i] = i * price[0];
    }
    
    for(int idx = 1; idx < N; idx++){
        for(int n = 0; n <= N; n ++){
            int notPick = 0 + dp[idx - 1][n];
            int pick = INT_MIN;
            int rodeLen = idx + 1;
            if(rodeLen <= n){
               pick = price[idx] + dp[idx][n - rodeLen]; 
            }

            dp[idx][n] = max(pick , notPick);
        }
    }
    
    return dp[N - 1][N]; 
}
int helper_spaceOpt(vector<int> &price, int N){  // n = 5
    vector<int> prev (N + 1, 0), curr(N + 1, 0);
    
    for(int i = 0; i<=N; i++){
        prev[i] = i * price[0];
    }
    
    for(int idx = 1; idx < N; idx++){
        for(int n = 0; n <= N; n ++){
            int notPick = 0 + prev[n];
            int pick = INT_MIN;
            int rodeLen = idx + 1;
            if(rodeLen <= n){
               pick = price[idx] + curr[n - rodeLen]; 
            }

            curr[n] = max(pick , notPick);
        }
        prev = curr;
    }   
    return prev[N]; 
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
//     vector<vector<int>> dp(n , vector<int> (n + 1, -1));
//     return helper(n - 1, price, n, dp);
//     return helper_tebu(price, n);
    return helper_spaceOpt(price, n);
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i<n ; i++) cin >> a[i];
    cout << cutRod(a, n);
}