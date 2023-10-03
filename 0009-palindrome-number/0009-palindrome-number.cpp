class Solution {
public:
    bool isPalindrome(int x) {
        if(x >= 0)
        {
            long reverse = 0;
            int temp = x;
            while(temp != 0)
            {
                reverse = (reverse*10) + (temp%10);
                temp /= 10;
            }
            return (reverse == x);
        }
        else
            return false;
    }
};