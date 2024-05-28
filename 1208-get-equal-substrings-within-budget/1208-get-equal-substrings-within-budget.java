class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int n = s.length();
        int ans = 0;
        int window = 0;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            window += Math.abs((int)s.charAt(right) - (int)t.charAt(right));
            
            while (window > maxCost) {
                window -= Math.abs((int)s.charAt(left) - (int)t.charAt(left));
                left += 1;
            }
            
            ans = Math.max(ans, (right - left + 1));
        }
        
        return ans;
    }
}