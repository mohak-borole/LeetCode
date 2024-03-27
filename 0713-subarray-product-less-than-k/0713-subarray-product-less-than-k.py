class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        start = 0
        end = 0
        count = 0
        product = 1
    
        while end < len(nums):
            product *= nums[end]
        
            while start <= end and product >= k:
                product /= nums[start]
                start += 1
        
            if product < k:
                count += end - start + 1
        
            end += 1
    
        return count