class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_wat = 0 , i = 0 , j = height.size()-1;
        
        while(i < j){
            int Area = (min(height[i] , height[j])) * (j - i);
            max_wat = max(max_wat , Area);
            if(height[i] <= height[j]) i++;
            else if(height[i] > height[j]) j--;            
        }
        
        return max_wat;
    }
};