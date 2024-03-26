class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,bool> mp;
        
        for(int num : nums) {
            if(num > 0 && num <= nums.size()) {
                mp[num] = 1;
            }
        }
        
        int i = 1;
        while(1) {
            if(mp[i])
                i++;
            else return i;
        }
    }
};