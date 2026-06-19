class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2) {
            return false;
        }
        // Use a stack to keep track of the past braces
        std::stack<char> braces;
        std::unordered_map<char, char> map;
        map['('] = ')';
        map['{'] = '}';
        map['['] = ']';

        for (char c : s) {
            // iterate through the string
            if (c == '(' || c == '{' || c == '[') {
                braces.push(c);
            }
            // If we see a closing brace, pop from the stack to find matching 
            else if (!braces.empty() && map.at(braces.top()) == c) {
                braces.pop();
            }
            // If it doesnt match, return false
            else {
                return false;
            }

        }
        return braces.empty();
    }
};

