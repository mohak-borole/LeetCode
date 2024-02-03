#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int func(int ind , vector<int> &arr , int k , vector<int> &dp) {
        if(ind == arr.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        int len = 0;
        int maxi = 0;
        int maxAns = 0;
        for(int j = ind ; j < min(static_cast<int>(arr.size()), ind+k) ; j++) {
            len++;
            maxi = max(maxi , arr[j]);
            int sum = (len * maxi) + func(j+1 , arr, k , dp);
            
            maxAns = max(maxAns , sum);
        }
        
        return dp[ind] = maxAns;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int size = arr.size();
        vector<int> dp(size , -1);
        return func(0 , arr , k , dp);
    }
};