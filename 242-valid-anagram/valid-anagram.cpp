class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char,int> sMap;
        std::unordered_map<char,int> tMap;
        
        for (char c : s) {
            sMap[c]++;
        }
        for (char c : t) {
            tMap[c]++;
        }
        return sMap == tMap;
    }
};