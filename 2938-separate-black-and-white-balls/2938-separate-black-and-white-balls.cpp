class Solution {
public:
    int minimumSteps(string s) {
        int white = 0;
        int res = 0;
        int n = s.length();

        for(int i = 0 ; i < n ; ++i) {
            if(s[i] == '0') {
                res += white;
            } else if (s[i] == '1') {
                white++;
            }
        }

        return res;
    }
};