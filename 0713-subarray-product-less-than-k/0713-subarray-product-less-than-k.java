class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int start = 0, end = 0, count = 0;
        long product = 1; // Using long to prevent integer overflow
        
        while (end < nums.length) {
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
}