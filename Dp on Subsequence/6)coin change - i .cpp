// https://leetcode.com/problems/coin-change/
// 

#include<bits/stdc++.h>
using namespace std;
int helper(int idx , vector<int> & a, int T){
        if(idx == 0){
            if(T % a[0] == 0){
                return T / a[0];
            }
            return 1e9;
        }
        int notPick = 0 + helper(idx - 1, a, T);
        int pick = 1e9;
        if(T - a[idx] >= 0){
            pick = 1 + helper(idx , a , T - a[idx]);
        }
        
        return min (pick , notPick);
    }
    int helper_memo(int idx , vector<int> & a, int T, vector<vector<int>> &dp){
        if(idx == 0){
            if(T % a[0] == 0){
                return T / a[0];
            }
            return 1e9;
        }
         if(dp[idx][T] != -1) return dp[idx][T];
        int notPick = 0 + helper(idx - 1, a, T);
        int pick = 1e9;
        if(T - a[idx] >= 0){
            pick = 1 + helper(idx , a , T - a[idx]);
        }
        
        return dp[idx][T] = min (pick , notPick);
    }
    int helper_tebu(vector<int> & a, int target){
        int n = a.size();
        vector<vector<int>> dp(a.size(), vector<int> (target + 1 , 0));
        for(int T =0; T  <= target; T++){
            if(T % a[0] == 0){
                dp[0][T] = T / a[0];
            }
            else dp[0][T] = 1e9;
        }
        for(int idx = 1; idx < n; idx ++){
            for(int T = 0; T<= target; T++){
                int notPick = 0 + dp[idx - 1][T];
                int pick = 1e9;
                if(T - a[idx] >= 0){
                    pick = 1 + dp[idx][T - a[idx]];
                }

                dp[idx][T] = min (pick , notPick);
            }
        }
        return dp[n - 1][target];
       
    }
    int helper_space_opt(vector<int> & a, int target){
        int n = a.size();
        vector<int> prev(target + 1 , 0), curr(target + 1, 0);
        for(int T =0; T  <= target; T++){
            if(T % a[0] == 0){
                prev[T] = T / a[0];
            }
            else prev[T] = 1e9;
        }
        for(int idx = 1; idx < n; idx ++){
            for(int T = 0; T<= target; T++){
                int notPick = 0 + prev[T];
                int pick = 1e9;
                if(T - a[idx] >= 0){
                    pick = 1 + curr[T - a[idx]];
                }

                curr[T] = min (pick , notPick);
            }
            prev = curr;
        }
        return prev[target];
       
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1 , -1));
        // int ans = helper_memo(coins.size() - 1 , coins, amount, dp);
        // int ans = helper(coins.size() - 1 , coins, amount);
        // int ans = helper_tebu(coins, amount);
        int ans = helper_space_opt(coins, amount);
        if(ans != 1e9){
            return ans;
        }
        return -1;
        
    }

    int main(){
         int n, target;
        cin >> n >> target;
        vector<int> denominations(n);
        for(int i = 0; i<n ; i++) cin >> denominations[i];
        cout << coinChange(denominations, target);
    }