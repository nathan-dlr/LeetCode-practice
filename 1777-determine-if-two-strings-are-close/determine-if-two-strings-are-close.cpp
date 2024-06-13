class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {return false;}
        map<char, int> letters1;
        map<char, int> letters2;
        map<int, int> occur1;
        map<int, int> occur2;
        bool match = true;

        bool swap_cond = true;
        for (int i = 0; i < word1.size(); i++) {
            letters1[word1[i]]++;
            letters2[word2[i]]++;
        }
        if (letters1.size() != letters2.size()) {return false;}

        for (auto& letters : letters1) {
            occur1[letters.second]++;
        }
        for (auto& letters : letters2) {
            occur2[letters.second]++;
            if (letters1.find(letters.first) == letters1.end()) {return false;}
        }
        for (auto& occurrences : occur1) {
            if (occurrences.second != occur2[occurrences.first]) {
                match = false;
            }
        }
        if (match == false) {return false;}
        return true;
    }
};