class Solution {
    public String minRemoveToMakeValid(String s) {
        Stack<Integer> par = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                par.push(i);
            } else if (s.charAt(i) == ')') {
                if (!par.isEmpty()) {
                    par.pop();
                } else {
                    s = s.substring(0, i) + '*' + s.substring(i + 1); // Marking ')' for removal
                }
            }
        }

        while (!par.isEmpty()) {
            int index = par.pop();
            s = s.substring(0, index) + '*' + s.substring(index + 1); // Marking '(' for removal
        }

        StringBuilder result = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c != '*') {
                result.append(c);
            }
        }

        return result.toString();
    }
}