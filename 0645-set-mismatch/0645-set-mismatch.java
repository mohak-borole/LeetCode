class Solution {
    public int[] findErrorNums(int[] nums) {
        int N = nums.length, sum = N * (N + 1) / 2;
        int[] result = new int[2];
        boolean[] seen = new boolean[N+1];
        for (int num : nums) {
            sum -= num;
            if (seen[num]) result[0] = num;
            seen[num] = true;
        }
        result[1] = sum + result[0];
        return result;
    }
}