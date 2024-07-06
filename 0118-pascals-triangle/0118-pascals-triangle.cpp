class Solution {
public:
    vector<int> generateRow(int row) {
        long long ans = 1;
        vector<int> Row ;
        Row.push_back(ans);
        
        for(int col = 1 ; col < row ; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            Row.push_back(ans);
        }
        
        return Row;
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pas_triangle;
        
        for(int row = 1 ; row <= numRows ; row++) {
            pas_triangle.push_back(generateRow(row));
        }
        
        return pas_triangle;
   }
};