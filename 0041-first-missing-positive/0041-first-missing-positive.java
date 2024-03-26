class Solution {
    public int firstMissingPositive(int[] nums) {
        Map<Integer , Boolean> mp = new HashMap<>();
        
        for(int num : nums) {
            if(num > 0 && num <= nums.length) {
                mp.put(num , true);
            }
        }
        
        int i = 1;
        while(true) {
            if(mp.containsKey(i))
                i++;
            else return i;
        }
    }
}