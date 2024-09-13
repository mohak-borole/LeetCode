class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> answer;

        for(auto quer : queries) {
            int XORres = arr[quer[0]];
            for(int i = quer[0]+1 ; i <= quer[1] ; i++) {
                XORres = XORres ^ arr[i];
            }
            answer.push_back(XORres);
        }

        return answer;
    }
};