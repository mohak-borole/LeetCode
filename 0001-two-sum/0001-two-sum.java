class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        for(int i = 0 ; i < n ; i++)
        {
            int result[] = new int[2];
            for(int j = i+1 ; j < n ; j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    return new int[]{i , j};
                }
            }
        }
        return new int[]{};
    }
}