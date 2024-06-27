class Solution {
public:
    string decodeString(string s) {
        string result;
        string substr;
        string temp;
        int open_brackets = 0;
        int closed_brackets = 0;
        stack<string> substrings;
        stack<int> nums;
        bool mul_digs = false;
        int curr_num = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                if (!mul_digs) {
                    nums.push(s[i] - 0x30);
                    mul_digs = true;
                }
                else {
                    curr_num = nums.top() * 10 + (s[i] - 0x30);
                    nums.pop();
                    nums.push(curr_num);
                }
            }
            else if (s[i] == '[') {
                mul_digs = false;
                if (!substr.empty()) {
                    result += substr;
                    substr.clear();
                }
                do {
                    if (s[i] == '[') {
                        open_brackets++;
                    }
                    else if (s[i] == ']') {
                        closed_brackets++;
                    }
                    substr += s[i];
                    i++;
                }
                while (open_brackets != closed_brackets);
                substr.pop_back();
                substr.erase(0, 1);
                i -= 2;
                substr = decodeString(substr);
            }
            else if (s[i] == ']') {
                mul_digs = false;
                temp = decodeString(substr);
                substr.clear();
                if (temp.empty()) {
                    continue;
                }
                curr_num = nums.top();
                nums.pop();
                while (curr_num != 0) {
                    substr += temp;
                    curr_num--;
                }
                temp.clear();
                if (substrings.empty()) {
                    result += substr;
                    substr.clear();
                }
                else {
                    substr = substrings.top() + substr;
                    substrings.pop();
                }
            }
            else {
                mul_digs = false;
                substr += s[i];
            }
        }
        result += substr;
        return result;
    }
};