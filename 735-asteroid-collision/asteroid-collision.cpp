class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (int i = 0; i < asteroids.size(); i++) {
            if (result.empty()) {
                result.push_back(asteroids[i]);
            }
            else if (asteroids[i] < 0) {
                if (result.back() < 0) {
                    result.push_back(asteroids[i]);
                }
                else {
                    while (true)
                        if (result.empty()) {
                            result.push_back(asteroids[i]);
                            break;
                        }
                        else if (result.back() < 0) {
                            result.push_back(asteroids[i]);
                            break;
                        }
                        else if (abs(result.back()) < abs(asteroids[i])) {
                            result.pop_back();
                        }
                        else if (abs(result.back()) == abs(asteroids[i])) {
                            result.pop_back();
                            break;
                        }
                        else {
                            break;
                        }
                }
            }
            else {
                result.push_back(asteroids[i]);
            }
        }
        return result;
    }
};