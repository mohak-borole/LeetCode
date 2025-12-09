class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1'000'000'007;
        int n = nums.size();
        
        // right[x] = how many times x appears in suffix starting at current j
        unordered_map<long long, long long> right, left;
        
        for (int x : nums) {
            right[x]++;
        }
        
        long long ans = 0;
        
        for (int j = 0; j < n; ++j) {
            // j moves from left to right: remove nums[j] from "right" side
            right[nums[j]]--;
            
            long long target = 2LL * nums[j];
            
            long long cntLeft  = left[target];   // nums[i] == target, i < j
            long long cntRight = right[target];  // nums[k] == target, k > j
            
            ans = (ans + (cntLeft % MOD) * (cntRight % MOD)) % MOD;
            
            // now nums[j] becomes part of the left side for future j's
            left[nums[j]]++;
        }
        
        return (int)(ans % MOD);
    }
};
