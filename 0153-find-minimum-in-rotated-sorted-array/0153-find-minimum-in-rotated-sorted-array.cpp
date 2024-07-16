class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;

        // If the array is not rotated (the smallest element is the first element)
        if (nums[left] <= nums[right]) {
            return nums[left];
        }

        // Binary search to find the inflection point
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Check if mid element is smaller than its next element
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            
            // Check if mid element is smaller than its previous element
            if (nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }

            // Adjust the search range
            if (nums[mid] > nums[left]) {
                // If mid element is greater than the leftmost element, the smallest element is in the right half
                left = mid + 1;
            } else {
                // If mid element is less than or equal to the leftmost element, the smallest element is in the left half
                right = mid - 1;
            }
        }

        return -1; // This should never be reached if input array is a rotated sorted array
    }
};