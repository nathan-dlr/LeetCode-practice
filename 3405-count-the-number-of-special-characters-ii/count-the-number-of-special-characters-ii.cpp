class Solution {
public:
    int numberOfSpecialChars(string word) {
        std::set<char> lower;
        std::set<char> upper;
        std::set<char> special;
        std::set<char> notSpecial;
        for (char letter : word) {
            // Lowercase
            if (0x61 <= letter && letter <= 0x7A) {
                lower.insert(letter);
                if (upper.contains(letter - 0x20)) {
                    special.erase(letter);
                    notSpecial.insert(letter);
                }
            }
            // Uppercase
            else {
                char lowerCase = letter + 0x20;
                upper.insert(letter);
                if (lower.contains(lowerCase) && !notSpecial.contains(lowerCase)) {
                    special.insert(lowerCase);
                }

            }
        }
        return special.size();
    }
};