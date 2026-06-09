class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string,int> map;
        vector<vector<string>> result;
        int index = 0;
        for (int i = 0; i < strs.size(); i++) {
            std::string copy = strs[i];
            std::sort(strs[i].begin(), strs[i].end());
            
            if (!map.contains(strs[i])) {
                map[strs[i]] = index++;
                result.push_back({}); 
            }
            result[map[strs[i]]].push_back(copy);
        }
        return result;
    }
};