class Solution {
public:
    bool isValid(string s) {
        // Use a stack to keep track of the past braces
        std::stack<char> braces;
    

        for (char c : s) {
            // iterate through the string
            if (c == '(' || c == '{' || c == '[') {
                braces.push(c);
            }
            // If we see a closing brace, pop from the stack to find matching 
            else if (braces.empty()) {
                return false;
            }
            // If it doesnt match, return false
            else {
                char top = braces.top();
                if (c == ')' && top != '(') {
                    return false;
                }
                else if (c == '}' && top != '{') {
                    return false;
                }
                else if (c == ']' && top != '[') {
                    return false;
                }
                braces.pop();
            }
        }
        return braces.empty();
    }
};

