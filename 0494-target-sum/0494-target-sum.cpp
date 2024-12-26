class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums , target , 0 , 0);
    }

    int helper(vector<int>& nums , int target , int idx , int sum) {
        if(idx >= nums.size())
            return sum == target ? 1:0;

        int subtract = helper(nums , target , idx + 1 , sum - nums[idx]);
        int add = helper(nums , target , idx + 1 , sum + nums[idx]);

        return subtract + add;
    }
};