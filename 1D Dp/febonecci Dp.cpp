#include <bits/stdc++.h>

using namespace std;

// vector<int> dp(10000, -1);

int f_reculsion(int idx){
    if(idx <= 1) return idx;  
    
    int left = f_reculsion(idx - 1);
    int right = f_reculsion(idx - 2);
    
    return left + right;
}

int f_memo(int idx, vector<int> &dp){
    if(idx <= 1) return idx;  
    
    if(dp[idx] != -1) return dp[idx]; // step 2
    
    int left = f_memo(idx - 1, dp);
    int right = f_memo(idx - 2, dp);
    
    return dp[idx] = left + right;  // step 3
}

int main()
{
    int n;
    cin >> n;
    
   // vector<int> dp(n + 1, -1) ; // step 1
    
   // cout << f_reculsion(n); // tc --> o(2^n) // sc --> o(n)

   
  // cout << f_memo(n, dp);  // tc --> o(n) // sc --> o(n) + o(n)
  
  
  // tebulation --> Tc - > o(n) / sc ---> o(n)
  /*
   vector<int> dp(n + 1);
   dp[0] = 0;
   dp[1] = 1;
   
   for(int idx = 2; idx <=n; idx++){
        int left = dp[idx - 1]; 
        int right = dp[idx - 2];
        
        dp[idx] = left + right; 
   }
   
   cout <<  dp[n];
   */
   
   // Space Optimazation 
   // Tc --> o(n)
   // sc --> o(1)
   int prev_2 = 0;
   int prev = 1;
   
   for(int idx = 2; idx <=n; idx++){
        int left = prev; 
        int right = prev_2;
        
        int curr_i = left + right; 
        
        prev_2 = prev;
        prev = curr_i;
   }
   
   cout <<  prev;
   
    return 0;
}