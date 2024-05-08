class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        n = len(score)

        maxScore = max(score)

        score2Index = [0] * (maxScore + 1)

        for i in range(n):
            score2Index[score[i]] = i + 1

        ans = [""] * n

        place = 1

        for i in range(maxScore, -1, -1):

            if score2Index[i] == 0:
                continue

            actualIndex = score2Index[i] - 1
            if place == 1:
                ans[actualIndex] = "Gold Medal"
            elif place == 2:
                ans[actualIndex] = "Silver Medal"
            elif place == 3:
                ans[actualIndex] = "Bronze Medal"
            else:
                ans[actualIndex] = str(place)
            place += 1

        return ans