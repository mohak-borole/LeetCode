class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        int left = 0, right = n - 1;
        
        // If the array is not rotated.
        if (nums[left] <= nums[right]) {
            return nums[left];
        }
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Check if mid is the inflection point
            if (mid > left && nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }
            if (mid < right && nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            
            // Adjust the search range
            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1; // This should never be reached if the input array is a rotated sorted array
    }
}