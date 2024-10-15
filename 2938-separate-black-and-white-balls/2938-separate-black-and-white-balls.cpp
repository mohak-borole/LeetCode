class Solution {
public:
    long long minimumSteps(string s) {
        long long white = 0;
        long long res = 0;
        long long n = s.length();

        for(long long i = 0 ; i < n ; ++i) {
            if(s[i] == '0') {
                res += white;
            } else if (s[i] == '1') {
                white++;
            }
        }

        return res;
    }
};