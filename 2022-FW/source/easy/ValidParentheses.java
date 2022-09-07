package easy;

import java.util.Stack;

class ValidParentheses {
    public boolean isValid(String s) {
        char[] braces = s.toCharArray();
        Stack<Character> stack = new Stack<>();
        stack.push(braces[braces.length - 1]);
        
        for (int i = braces.length - 2; i >= 0; i--) {
            if (isClose(braces[i])) {
                stack.push(braces[i]);
            } else if (stack.isEmpty()) {
                return false;
            } else {
                char fromStack = stack.pop();
                if (!isMatch(braces[i], fromStack)) {
                    stack.push(fromStack);
                    stack.push(braces[i]);
                }
            }
        }
        
        return stack.isEmpty();
    }
    
    private boolean isClose(char c) {
        if (c == ')' || c == '}' || c == ']') {
            return true;
        }
        return false;
    }

    
    private boolean isMatch(char c1, char c2) {
        if (c1 == '(' && c2 == ')') {
            return true;
        } else if (c1 == '{' && c2 == '}') {
            return true;
        } else if (c1 == '[' && c2 == ']') {
            return true;
        }
        return false;
    }
}