string group_length(int count) {
    int num;
    char num_chr;
    string num_str;
    while (count) {
        num = count % 10;
        num_chr = num + 48;
        num_str.insert(num_str.begin(), num_chr);
        count = count / 10;
    }
    return num_str;
} 

class Solution {
public:
    int compress(vector<char>& chars) {
        string s;
        string num_str;
        int size = chars.size();
        char current = chars[0];
        int count = 0;

        for (int i = 0; i < size; i++) {
            if (chars[i] != current) {
                s.push_back(current);
                num_str = group_length(count);
                if (num_str != "1") {s += num_str;}
                current = chars[i];
                count = 1;
            }
            else {
                count++;
            }
        }
        s.push_back(current);
        num_str = group_length(count);
        if (num_str != "1") {s += num_str;}

        chars.clear();
        for (int i = 0; i < s.size(); i++) {
            chars.push_back(s[i]);
        }
        return chars.size();
    }
};