// https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980?leftPanelTab=0
#include<bits/stdc++.h>
using namespace std;
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
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
    int totalSum = 0;
    for(auto it: arr){
        totalSum += it;
    }
    if(totalSum % 2 == 1) return false;
    else{
        int targetSum = totalSum / 2;
        if(helper_space_opt(targetSum, arr)){
            return true;
        }
        return false;
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    if(canPartition(v, n) == 1){
        cout <<"TRUE" << endl;
    }
    else{
        cout <<"FALSE" << endl;
    }
}
