class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: (x[0], x[1]))
        count = 0
        prevlast = points[0][1]

        for i in range(1, len(points)):
            if prevlast >= points[i][0]:
                if prevlast > points[i][1]:
                    prevlast = points[i][1]
            else:
                prevlast = points[i][1]
                count += 1

        return count + 1