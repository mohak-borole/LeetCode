class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0, end = 0, count = 0;
        long long product = 1; // Using long long to prevent integer overflow
        
        while (end < nums.size()) {
            product *= nums[end];
            
            while (start <= end && product >= k) {
                product /= nums[start];
                start++;
            }
            
            if (product < k)
                count += end - start + 1;
            
            end++;
        }
        
        return count;
    }
};