class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, result, combination, 0);
        return result;
    }
    
private:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& combination, int start) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            
            if (candidates[i] > target) break;  // No point in continuing if the number is greater than the target
            
            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], result, combination, i + 1);
            combination.pop_back();  // Backtrack
        }
    }
};
