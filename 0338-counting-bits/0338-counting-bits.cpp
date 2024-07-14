class Solution {
public:
    int count(int n) {
        int setBits = 0;
        
        for(int i = 31 ; i >= 0 ; i--) if((n&(1 << i)) != 0) setBits++;
        
        return setBits;
    }
    vector<int> countBits(int n) {
        vector<int> result (0, n+1);
        
        for(int i = 0 ; i <= n ; i++) result.push_back(count(i));
        
        return result;
    }
};