class Solution {
public:
    int maxNumberOfBalloons(string text) {
        std::unordered_map<char,int> map;
        for (auto letter : text) {
            map[letter]++;
        }

        int min1 = std::min(map['b'], std::min(map['a'], map['n']));
        int min2 = std::min(map['l'], map['o']) / 2;
        return std::min(min1, min2);
    }
};