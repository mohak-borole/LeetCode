class Solution {
    public int firstUniqChar(String s) {
        int[] count = new int[26];
        for(char ch : s.toCharArray())
            count[ch-'a']++;
        
        int n = s.length();
        for(int i = 0 ; i < n ; i++) {
            if(count[s.charAt(i)-'a'] == 1)
                return i;
        }
        return -1;
    }
}