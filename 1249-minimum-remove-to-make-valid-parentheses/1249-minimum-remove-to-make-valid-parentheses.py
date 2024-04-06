class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        par = []
        for i in range(len(s)):
            if s[i] == '(':
                par.append(i)
            elif s[i] == ')':
                if par:
                    par.pop()
                else:
                    s = s[:i] + '*' + s[i+1:]  # Marking ')' for removal
        
        while par:
            s = s[:par[-1]] + '*' + s[par[-1]+1:]  # Marking '(' for removal
            par.pop()
        
        result = ''
        for c in s:
            if c != '*':
                result += c
        
        return result