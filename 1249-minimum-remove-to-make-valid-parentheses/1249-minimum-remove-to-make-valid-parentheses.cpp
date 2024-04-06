class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> par;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                par.push(i);
            } else if (s[i] == ')') {
                if (!par.empty()) {
                    par.pop();
                } else {
                    s[i] = '*'; // Marking ')' for removal
                }
            }
        }

        while (!par.empty()) {
            s[par.top()] = '*'; // Marking '(' for removal
            par.pop();
        }

        string result;
        for (char c : s) {
            if (c != '*') {
                result += c;
            }
        }

        return result;
    }
};