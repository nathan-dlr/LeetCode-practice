class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;
        s.push_back(' ');
        for (char letter : s) {
            if (letter != ' ') {
                word += letter;
            }
            else if (!word.empty()) {
                words.push_back(word);
                word.erase();
            }
        }

        string new_sentence;
        int end = words.size();
        for (int i = 0; i < end; i++) {
            new_sentence += words.back();
            words.pop_back();
            new_sentence += " ";
        }
        new_sentence.pop_back();
        return new_sentence;
    }
};