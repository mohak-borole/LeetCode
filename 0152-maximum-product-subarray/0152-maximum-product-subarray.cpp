class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double leftProduct = 1;
        double rightProduct = 1;
        double ans =  nums[0];
        for(int i=0;i<nums.size();i++){
            if(leftProduct==0){
                leftProduct=1;
            }
            if(rightProduct==0){
                rightProduct=1;
            }
            leftProduct = leftProduct * nums[i];
            rightProduct = rightProduct * nums[nums.size()-i-1];
            ans  = max(ans,max(leftProduct,rightProduct));
        }
        return (int)ans;
    }
};