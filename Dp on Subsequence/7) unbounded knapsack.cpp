#include <bits/stdc++.h> 
using namespace std;
int helper_memo(int idx, int W, vector<int> &value, vector<int> &wt, vector<vector<int>>& dp){
    
    if(idx == 0){
         if(W >= wt[0]){
            return ((int)(W / wt[0])) * value[0];
         }
        else return 0;
    }    
    if(dp[idx][W] != -1) return dp[idx][W];
    int notPick = 0 + helper_memo(idx - 1, W, value, wt, dp);
    int pick = INT_MIN;
    if(W - wt[idx] >= 0){
        pick = value[idx] + helper_memo(idx, W - wt[idx], value, wt, dp);
    }
    
    return dp[idx][W] = max(pick , notPick);
}
int helper_tebu( int W, vector<int> &value, vector<int> &wt){
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int> (W + 1, 0));   // idx = 0 // dp[0][]  // 0 ----> W
    for(int w = 0; w <= W; w++){
        dp[0][w] = ((int)(w / wt[0])) * value[0];
    }
    for(int idx = 1; idx< n; idx++){
        for(int w = 0; w <= W; w++){
            int notPick = 0 + dp[idx - 1][w];
            int pick = INT_MIN;
            if(w - wt[idx] >= 0){
                pick = value[idx] + dp[idx][w - wt[idx]];
            }

            dp[idx][w] = max(pick , notPick);
        }
    }
    
    return dp[n - 1][W];
    
}
int helper_space_opt( int W, vector<int> &value, vector<int> &wt){
    int n = wt.size();
    // vector<vector<int>> dp(n, vector<int> (W + 1, 0));   // idx = 0 // dp[0][]  // 0 ----> W
    
    vector<int> prev (W + 1, 0), curr(W +1 , 0);
    
    for(int w = 0; w <= W; w++){
        prev[w] = ((int)(w / wt[0])) * value[0];
    }
    for(int idx = 1; idx< n; idx++){
        for(int w = 0; w <= W; w++){
            int notPick = 0 + prev[w];
            int pick = INT_MIN;
            if(w - wt[idx] >= 0){
                pick = value[idx] + curr[w - wt[idx]];
            }

            curr[w] = max(pick , notPick);
        }
        prev = curr;
    }
    
    return prev[W];
    
}
int unboundedKnapsack(int n, int W, vector<int> &value, vector<int> &wt)
{
    // Write Your Code Here.
  //  vector<vector<int>> dp(n, vector<int> (W + 1, -1));
  //  return helper_memo(n - 1, W, value, wt, dp);
//     return helper_tebu( W, value, wt);
     return helper_space_opt( W, value, wt);
}

int main(){
    int n;
    int W;
    cin >> n >> W;
    vector<int> val(n), wt(n);

    for(int i = 0; i< n; i++){
        cin >> wt[i];
    }
    for(int i = 0; i< n; i++){
        cin >> val[i];
    }
   cout <<  unboundedKnapsack(n, W, val, wt);

}