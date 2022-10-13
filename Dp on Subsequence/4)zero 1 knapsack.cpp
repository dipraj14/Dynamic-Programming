#include<bits/stdc++.h>
using namespace std;
int helper(vector<int> &wt, vector<int> &val, int idx, int C, vector<vector<int>> &dp){
    if(idx == 0){
        if(wt[0] <= C) return val[0];
        else return 0;
    }
    if(dp[idx][C] != -1) return dp[idx][C];
    int notPick = 0 + helper(wt, val, idx - 1, C, dp);
    int pick = INT_MIN;
    if(wt[idx] <= C) {
       
         pick = val[idx] + helper(wt, val, idx - 1, C - wt[idx], dp);
    }
    
    return  dp[idx][C] = max(pick, notPick);
}
/*
int knapsack(vector<int> wt, vector<int> val, int n, int W) 
{
	// Write your code here
    // TEbulation --> TC - > o(n * W) | Sc -> o(n * W)
    /*
    vector<vector<int>> dp(n, vector<int> (W + 1, 0));
    for(int i = wt[0]; i<=W; i++){
        dp[0][i] = val[0];
    }
    
    for(int idx = 1; idx < n; idx++){
        for(int C = 0; C <= W; C++){
             int notPick = 0 + dp[idx - 1][C];
            int pick = INT_MIN;
            if(wt[idx] <= C) {

                 pick = val[idx] + dp[idx - 1][C - wt[idx]];
            }

            dp[idx][C] = max(pick, notPick);
        }
    }
    
    return dp[n-1][W];
*/
    // Space Optimazation --> TC - > o(n * W) | Sc -> O(W + W);
/*
    vector<int> prev (W +1, 0) , curr(W + 1, 0);
    for(int i = wt[0]; i<=W; i++){
        prev[i] = val[0];
    }
    
    for(int idx = 1; idx < n; idx++){
        for(int C = 0; C <= W; C++){
             int notPick = 0 + prev[C];
            int pick = INT_MIN;
            if(wt[idx] <= C) {

                 pick = val[idx] + prev[C - wt[idx]];
            }

            curr[C] = max(pick, notPick);
        }
        prev = curr;
    }
    
    return prev[W];
    
    
    // 
    // Ultimate_Space Optimazation  --> TC - > o(n * W) | Sc -> O(W);
    // H/W --> 
    vector<int> prev (W +1, 0);
    for(int i = wt[0]; i<=W; i++){
        prev[i] = val[0];
    }
    
    for(int idx = 1; idx < n; idx++){
        for(int C = W; C >= 0; C--){
             int notPick = 0 + prev[C];
            int pick = INT_MIN;
            if(wt[idx] <= C) {

                 pick = val[idx] + prev[C - wt[idx]];
            }

            prev[C] = max(pick, notPick);
        }
//         prev = curr;
    }
    
    return prev[W];
}
*/
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>> dp(n, vector<int> (maxWeight + 1, -1));
   return helper(weight,value, n - 1, maxWeight, dp);
}
int main(){
    int n;
    cin >> n;
    int W;cin >> W;
    vector<int> wt(n), val(n);
    for(int i=0; i<n; i++) cin >> wt[i];
    for(int i=0; i<n; i++) cin >> val[i];
    cout<< knapsack(wt, val, n, W);
}