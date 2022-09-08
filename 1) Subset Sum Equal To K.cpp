// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0
#include<bits/stdc++.h>
using namespace std;
bool helper(int idx, int target, vector<int> &arr, vector<vector<int>> &dp){  // o(n * target) --> Tc // o(n) + o(n) --> sc
    if(target == 0) return true;
    if(idx == 0) return arr[0] == target;
    
    if(dp[idx][target] != -1) return dp[idx][target];
    
    bool notPick = helper(idx - 1, target, arr, dp);
    bool pick = false;
    if(arr[idx] <= target){
        pick = helper(idx - 1, target - arr[idx], arr, dp);
    }
    return dp[idx][target] = pick or notPick;
}

bool helper_tebu(int k, vector<int> &arr){  // o(n * target) --> Tc //  o(n * target) --> sc
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    
    for(int i=0; i<n; i++){  // idx 
        dp[i][0] = true;
    }
    if(arr[0] <= k){ 
        dp[0][arr[0]] = true;
    }
    for(int idx = 1; idx <n; idx++){
        for(int target = 1; target <= k; target++){
            bool notPick = dp[idx - 1][target];
            bool pick = false;
            if(arr[idx] <= target){
                pick = dp[idx - 1][target - arr[idx]] ;
            }
            dp[idx][target] = pick or notPick;
            
        }
    }
    return dp[n-1][k];
}
bool helper_space_opt(int k, vector<int> &arr){  // o(n * target) --> Tc //  o(target) --> sc
    int n = arr.size();
    
    vector<bool> prev(k + 1, false);
    prev[0] = true;
 
    if(arr[0] <= k){ 
        prev[arr[0]] = true;
    }
    for(int idx = 1; idx <n; idx++){
        vector<bool> curr_i(k + 1, false);
        curr_i[0] = true;
        for(int target = 1; target <= k; target++){
            bool notPick = prev[target];
            bool pick = false;
            if(arr[idx] <= target){
                pick = prev[target - arr[idx]] ;
            }
            curr_i[target] = pick or notPick;
            
        }
        prev = curr_i;
    }
    return prev[k];
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    
//    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    
    
//     if(helper(n - 1, k, arr, dp)){
//         return true;
//     }
//     return false;
//     if(helper_tebu( k, arr)){
//         return true;
//     }
//     return false;
    
     if(helper_space_opt( k, arr)){
        return true;
    }
    return false;
    
}
int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    if(subsetSumToK(n, k, v) == 1){
        cout <<"TRUE" << endl;
    }
    else{
        cout <<"FALSE" << endl;
    }
}
