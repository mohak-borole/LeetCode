class Solution {
    public int func(int ind , int[] arr , int k , int[] dp) {
        if(ind == arr.length) return 0;
        if(dp[ind] != -1) return dp[ind];
        int len = 0;
        int maxi = 0;
        int maxAns = 0;
        for(int j = ind ; j < Math.min(arr.length, ind+k) ; j++) {
            len++;
            maxi = Math.max(maxi , arr[j]);
            int sum = (len * maxi) + func(j+1 , arr, k , dp);
            
            maxAns = Math.max(maxAns , sum);
        }
        
        return dp[ind] = maxAns;
    }
    
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int size = arr.length;
        int[] dp = new int[size];
        Arrays.fill(dp , -1);
        return func(0 , arr , k , dp);
    }
}