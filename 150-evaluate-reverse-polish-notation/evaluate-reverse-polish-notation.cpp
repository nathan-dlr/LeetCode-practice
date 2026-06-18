class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Use stack to store numbers
        std::stack<int> expression;

        for (string token : tokens) {
            int val{};
            auto [ptr, ec] = std::from_chars(token.data(), token.data() + token.size(), val);

            // If num, push to stack
            if (ec == std::errc{}) {
                expression.push(val);
                continue;
            }

            // If operator, perform operation on the last two numbers in the stack, and push result on stack
            val = expression.top();
            expression.pop();
            if (token == "+") {
                val += expression.top();
            }
            else if (token == "-") {
                val = expression.top() - val;
            }
            else if (token == "*") {
                val *= expression.top();
            }
            else {
                val = expression.top() / val;
            }
            expression.pop();
            expression.push(val);
        }
        // When done parsing tokens, the result should be the only number in the stack
        return expression.top();
    }
};