class Solution:
    def checkValidString(self, s: str) -> bool:
        open_count= 0
        for c in s:
            if c == '(' or c == '*':
                open_count += 1
            else:
                open_count -= 1

            if open_count < 0:  # If at any point, more ')' than '(' or '*' are encountered
                return False

        # Reset counter
        open_count = 0

        # Traverse from right to left, treating '*' as ')'
        for i in range(len(s) - 1, -1, -1):
            c = s[i]
            if c == ')' or c == '*':
                open_count += 1
            else:
                open_count -= 1

            if open_count < 0:  # If at any point, more '(' than ')' or '*' are encountered
                return False

        return True  # If all conditions are satisfied
