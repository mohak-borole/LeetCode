class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        mp = {}
        
        for num in nums:
            if num > 0 and num <= len(nums):
                mp[num] = True
        
        i = 1
        while True:
            if mp.get(i , False):
                i += 1
            else:
                return i