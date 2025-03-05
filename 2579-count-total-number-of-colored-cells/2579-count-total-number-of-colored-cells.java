class Solution {
    public static long coloredCells(int n) {
        return 1L + 2L * (long)(n - 1) * n;  // Formula: 2n(n-1) + 1
    }
}