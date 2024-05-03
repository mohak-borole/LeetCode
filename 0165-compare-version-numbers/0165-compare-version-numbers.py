class Solution:
    def compareVersion(self, v1: str, v2: str) -> int:
        n1, n2 = len(v1), len(v2)
        x1, x2 = 0, 0
        i, j = 0, 0
        while i < n1 or j < n2:
            while i < n1 and v1[i] != '.':
                x1 = 10 * x1 + int(v1[i])
                i += 1
            while j < n2 and v2[j] != '.':
                x2 = 10 * x2 + int(v2[j])
                j += 1
            if x1 < x2:
                return -1
            elif x1 > x2:
                return 1
            x1, x2 = 0, 0
            i += 1
            j += 1
        return 0