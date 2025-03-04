class Solution {
    public boolean checkPowersOfThree(int n) {
        int p = n;
        while(p > 0) {
            if (p%3 == 2){
                return false;
            }
            p = p /3;
        }
        return true;
    }
}