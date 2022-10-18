// code studio -> https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471
// leetCode - > https://leetcode.com/problems/coin-change-ii/
//
#include<bits/stdc++.h>
using namespace std;
long helper_memo(int idx, int T, vector<int> a, vector<vector<long>> &dp){
    if(idx == 0){
//         if(T % a[0] == 0) return 1;
//         return 0;
        return T % a[0] == 0;
    }
    if(dp[idx][T] != -1) return dp[idx][T];
    long notPick = helper_memo(idx - 1, T, a, dp);
    long pick = 0;
    if(T - a[idx] >= 0){
        pick = helper_memo(idx, T - a[idx], a, dp);
    }
    
    return dp[idx][T] = pick + notPick;
}
long helper_tebu( int target, vector<int> a, int n){
   vector<vector<long>> dp(n , vector<long> (target + 1));
   for(int T = 0; T<= target; T++){
       dp[0][T] = (T % a[0] == 0);
   }
    for(int idx = 1; idx < n; idx++){
        for(int T = 0; T<= target; T++){
            long notPick = dp[idx - 1][T];
            long pick = 0;
            if(T - a[idx] >= 0){
                pick = dp[idx][T - a[idx]];
            }
            dp[idx][T] = pick + notPick;
        }
    }
    return dp[n - 1][target];
}
long helper_space_opt( int target, vector<int> a, int n){
//    vector<vector<long>> dp(n , vector<long> (target + 1));
    vector<long> prev(target + 1), curr(target + 1);
   for(int T = 0; T<= target; T++){
       prev[T] = (T % a[0] == 0);
   }
    for(int idx = 1; idx < n; idx++){
        for(int T = 0; T<= target; T++){
            long notPick = prev[T];
            long pick = 0;
            if(T - a[idx] >= 0){
                pick = curr[T - a[idx]];
            }
            curr[T] = pick + notPick;
        }
        prev = curr;
    }
    return prev[target];
}
long countWaysToMakeChange(vector<int> denominations, int n, int target)
{
    //Write your code here
//     vector<vector<long>> dp(n , vector<long> (target + 1 , -1));
//     return helper_memo(n - 1, target, denominations, dp); // 
    //return helper_tebu(target, denominations, n);
    return helper_space_opt(target, denominations, n);
    
}

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> denominations(n);
    for(int i = 0; i<n ; i++) cin >> denominations[i];
    cout << countWaysToMakeChange(denominations, n, target);
}