// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

#include <bits/stdc++.h>
 
using namespace std;


int helper_memo(int idx, vector<int> &nums, vector<int> &dp){ // // o(n) -- > TC // o(n) + o(n) -->Sc
    if(idx == 0) return nums[idx];
    if(idx < 0) return 0;
    if(dp[idx] != -1) return dp[idx]; 
        // Pick
    int pick = nums[idx] + helper(idx - 2, nums, dp);
        //notPick
    int notPick = 0 + helper(idx - 1, nums, dp);
    
    return dp[idx] = max(pick, notPick);
}
int helper_tebu( vector<int> &nums){   // o(n) -- > TC // o(n) -->Sc
    int n = nums.size();
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    //if(idx < 0) return 0;
    for(int idx = 1; idx<n; idx++){
           // Pick
        int pick = nums[idx];
        if(idx > 1){
            pick += dp[idx - 2];
        }
            //notPick
        int notPick = 0 + dp[idx - 1];

         dp[idx] = max(pick, notPick);
    }
    
    return dp[n-1];
}
int helper_space_opt( vector<int> &nums){   // o(n) -- > TC // o(1) -->Sc
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    //if(idx < 0) return 0;
    for(int idx = 1; idx<n; idx++){
           // Pick
        int pick = nums[idx];
        if(idx > 1){
            pick += prev2;
        }
            //notPick
        int notPick = 0 + prev;

        int curr_i = max(pick, notPick);
        
        prev2 = prev;
        prev = curr_i;
    }
    
    return prev;
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
   // vector<int> dp(n, -1);
    //return helper_memo(n-1, nums, dp);
    
//     return helper_tebu(nums);
    return helper_space_opt(nums);
}

int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  cout << maximumNonAdjacentSum(v);
}