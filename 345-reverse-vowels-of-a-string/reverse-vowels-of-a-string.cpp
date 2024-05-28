class Solution {
public:
    string reverseVowels(string s) {
        string vowels;
        for (char letter : s) {
            char lower = tolower(letter);
            if (lower == 'a' || lower == 'e' || 
            lower == 'i' || lower == 'o' || 
            lower == 'u') {
                vowels.push_back(letter);
             }
        }

        for (int i = 0; i < s.size(); i++) {
            char letter = tolower(s[i]);
            if (letter == 'a' || letter == 'e' || 
            letter == 'i' || letter == 'o' || 
            letter == 'u') {
                s[i] = vowels[vowels.size() - 1];
                vowels.pop_back();
             }
        }
        return s;
    }
};