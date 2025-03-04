class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        p = n
        while p > 0:
            if p%3 == 2:
                return False
            p //= 3
        return True