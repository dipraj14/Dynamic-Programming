// https://www.codingninjas.com/codestudio/problems/house-robber_839733

#include <bits/stdc++.h>
 
using namespace std;

// note : Pre-req: Maximum Sum of non-adjacent elements

long long int helper_space_opt( vector<long long int> &nums){   // o(n) -- > TC // o(n) -->Sc
    int n = nums.size();
    vector<long long int> dp(nums.size());
    long long int prev = nums[0];
    long long int prev2 = 0;
    //if(idx < 0) return 0;
    for(int idx = 1; idx<n; idx++){
           // Pick
        long long int pick = nums[idx];
        if(idx > 1){
            pick += prev2;
        }
            //notPick
        long long int notPick = 0 + prev;

        long long int curr_i = max(pick, notPick);
        
        prev2 = prev;
        prev = curr_i;
    }
    
    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    if(valueInHouse.size() == 1) return valueInHouse[0];
    vector<long long int> temp1 /*0 - n-1 */, temp2  /* 1 - n-1 */;
    
    for(int i=0; i<valueInHouse.size(); i++){
        if(i != 0) temp2.push_back(valueInHouse[i]); // 1 - n-1 
        if(i != valueInHouse.size() -1) temp1.push_back(valueInHouse[i]); // 0 - n-2 
        
    }
    long long int ans1 = helper_space_opt(temp2);
    long long int ans2 = helper_space_opt(temp1);
    
    return max(ans1, ans2);
    
}
int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  cout << houseRobber(v);
}