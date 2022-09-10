
// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
 
using namespace std;
 
 
 
int solve_memo(int idx, vector<int> &hight, vector<int> &dp, int k){  // Time Complexity: O(N *K) //  Sc -> O(N) + O(N) ≈ O(N)
    if(idx == 0 ) return 0;
    
    if(dp[idx] != -1) return dp[idx];
    
    int min_Steps = INT_MAX;
    for(int j = 1; j<= k; j++){
        if(idx - j >= 0 ){
            int jump = solve_memo(idx - j , hight, dp, k) + abs(hight[idx] - hight[idx - j]);
            
            min_Steps = min(jump, min_Steps);
        }
       
    }
    
    
    return dp[idx] = min_Steps;
}

int solve_tebu(int n, vector<int>& height, int k){  // Time Complexity: O(N *K) //  Sc -> O(N)
     vector<int> dp(n);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mmSteps = INT_MAX;
        
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j]+ abs(height[i]- height[i-j]);
                mmSteps= min(jump, mmSteps);
            }
        }
        dp[i]= mmSteps;
    }
    return dp[n-1];
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    
    std::vector<int> hight(n);
    
    for(int i=0; i<n; i++){
        cin >> hight[i];
    }
 
    vector<int> dp(n , -1);
    
   //  cout << solve_memo(n - 1, hight, dp, k);
     cout << solve_tebu(n , hight, k);
   
 
    return 0;
}