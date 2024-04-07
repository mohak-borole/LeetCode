class Solution {
    public boolean checkValidString(String s) {
        int open = 0, closed = 0;

        // Traverse from left to right, treating '*' as '('
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '*')
                open++;
            else
                open--;

            if (open < 0) // If at any point, more ')' than '(' or '*' are encountered
                return false;
        }

        // Reset counters
        open = 0;
        
        // Traverse from right to left, treating '*' as ')'
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if (c == ')' || c == '*')
                open++;
            else
                open--;

            if (open < 0) // If at any point, more '(' than ')' or '*' are encountered
                return false;
        }

        return true; // If all conditions are satisfied
    }
}