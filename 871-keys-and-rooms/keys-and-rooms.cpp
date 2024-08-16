class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        map<int,int> visited;
        queue<int> keys;
        int curr_room;
        int new_key;
        keys.push(0);
        
        while (!keys.empty()) {
            curr_room = keys.front();
            keys.pop();
            visited.emplace(curr_room , 2);
            for (int i = 0; i < rooms[curr_room].size();i++) {
                new_key = rooms[curr_room][i];
                if (visited[new_key] > 0) {
                    continue;
                }
                else {
                    visited[new_key] = 1;
                    keys.push(new_key);
                }
            }
        }
        if (visited.size() == rooms.size()) {
            return true;
        }
        else {
            return false;
        }
    }
};