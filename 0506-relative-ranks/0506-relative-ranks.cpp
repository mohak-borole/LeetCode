class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        int n = score.size();

        int maxScore = 0;
        for (int i = 0; i < n; i++) {
            maxScore = std::max(maxScore, score[i]);
        }

        std::vector<int> score2Index(maxScore + 1);

        for (int i = 0; i < n; i++) {
            score2Index[score[i]] = i + 1;
        }

        std::vector<std::string> ans(n);

        int place = 1;

        for (int i = maxScore; i >= 0; i--) {

            if (score2Index[i] == 0) continue;

            int actualIndex = score2Index[i] - 1;
            if (place == 1) {
                ans[actualIndex] = "Gold Medal";
            }
            else if (place == 2) {
                ans[actualIndex] = "Silver Medal";
            }
            else if (place == 3) {
                ans[actualIndex] = "Bronze Medal";
            }
            else {
                ans[actualIndex] = std::to_string(place);
            }
            place++;
        }

        return ans;
    }
};