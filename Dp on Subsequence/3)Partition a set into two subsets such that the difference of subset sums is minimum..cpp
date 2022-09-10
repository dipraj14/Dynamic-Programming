#include<bits/stdc++.h>
using namespace std;
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    int totSum = 0;
    for(auto it: arr){
        totSum += it;
    }
    int k = totSum;
   
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
    // 
    int mini = INT_MAX;   // 0 1 2 3 4 5//    3 2 
    for(int s1=0; s1<= totSum/2; s1++){  // 0(T) 1(F) 2(T)
        if(prev[s1] == true){
            int s2 = totSum - s1; // 5 // 3
            mini = min(mini, abs(s1 - s2)); // 5 // 1
        }
    }
    
    return mini;
}

int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    cout << minSubsetSumDifference(v, n);
  
