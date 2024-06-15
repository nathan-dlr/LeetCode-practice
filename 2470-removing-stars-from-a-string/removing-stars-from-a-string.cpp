class Solution {
public:
    string removeStars(string s) {
        string new_s;
        int i = 0;        
        while (s.size() > i) {
            if (s[i] == '*') {
                new_s.pop_back();
            }
            else {
                new_s.push_back(s[i]);
            }
            i++;
        }
        return new_s;
    }
};