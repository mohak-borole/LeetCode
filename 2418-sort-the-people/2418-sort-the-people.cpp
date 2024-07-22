class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        for(int i = 0 ; i < n ; i++) {
            for(int j = i+1 ; j<n ; j++) {
                if(heights[i] < heights[j]) {
                    swap(heights[i] , heights[j]);
                    swap(names[i] , names[j]);
                }
            }
        }
        
        return names;
    }
};