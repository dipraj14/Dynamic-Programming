
//https://atcoder.jp/contests/dp/tasks/dp_a


#include <bits/stdc++.h>
 
using namespace std;
 
int solve(int idx, vector<int> &hight, vector<int> &dp){ // // tc -> o(n) // sc -> o(n) + o(n)
    if(idx == 0 ) return 0;
    
    if(dp[idx] != -1) return dp[idx];
    
    int jumpOne, jumpTwo = INT_MAX;
    
    jumpOne = solve(idx - 1 , hight, dp) + abs(hight[idx] - hight[idx - 1]);
    
    if(idx > 1){
        jumpTwo = solve(idx - 2, hight, dp) + abs(hight[idx] - hight[idx - 2]);
    }
    
    return dp[idx] = min(jumpOne, jumpTwo);
}

int solve_tebulation(vector<int> &hight){ // tc -> o(n) // sc -> o(n)
    int n = hight.size();
    vector<int> dp(n);
     dp[0] = 0;
     dp[1] = 0;
     
     for(int i=1; i<n; i++){
           int jumpOne, jumpTwo = INT_MAX;
    
        jumpOne = dp[i - 1] + abs(hight[i] - hight[i - 1]);
    
        if(i > 1){
            jumpTwo = dp[i - 2]  + abs(hight[i] - hight[i - 2]);
        }
        
       dp[i] = min(jumpOne, jumpTwo);
       
     }
     
     
     return dp[n - 1];
     
}
 
int solve_space_opt(vector<int> &hight){ // tc -> o(n) // sc ->  o(1)
    int n = hight.size();
 
    int prev = 0;
     int prev2 = 0;
     
     for(int i=1; i<n; i++){
           int jumpOne, jumpTwo = INT_MAX;
    
        jumpOne = prev + abs(hight[i] - hight[i - 1]);
    
        if(i > 1){
            jumpTwo = prev2  + abs(hight[i] - hight[i - 2]);
        }
        
       int curr_i = min(jumpOne, jumpTwo);
       
       prev2 = prev;
       prev = curr_i;
     }
     
     
     return prev;
     
}
int main()
{
    int n;
    cin >> n;
    
    std::vector<int> hight(n);
    
    for(int i=0; i<n; i++){
        cin >> hight[i];
    }
    
   // vector<int> dp(n , -1);
    
   // cout << solve(n - 1, hight, dp);
   
//    cout << solve_space_opt(hight);
 cout<< solve_tebulation(hight);
 
    return 0;
}