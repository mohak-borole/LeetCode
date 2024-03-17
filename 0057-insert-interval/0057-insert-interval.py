class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        ans = []
        start, end = newInterval
        
        inserted = False
        for inv in intervals:
            cstart, cend = inv
            
            if cend < start or inserted:
                ans.append([cstart, cend])
                continue
            
            start = min(start, cstart)
            if end < cstart:
                ans.append([start, end])
                ans.append([cstart, cend])
                inserted = True
                continue
            
            if end <= cend:
                ans.append([start, cend])
                inserted = True
        
        if not inserted:
            ans.append([start, end])
        
        return ans
