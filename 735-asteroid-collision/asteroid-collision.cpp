class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (int i = 0; i < asteroids.size(); i++) {
            cout << asteroids[i] << endl;
            if (result.empty()) {
                result.push_back(asteroids[i]);
            }
            else if (asteroids[i] < 0) {
                if (result.back() < 0) {
                    result.push_back(asteroids[i]);
                }
                else {
                    bool cond = true;
                    while (cond)
                        if (result.empty()) {
                            result.push_back(asteroids[i]);
                            cout << "pushing bc empty" << endl;
                            cond = false;
                        }
                        else if (result.back() < 0) {
                            result.push_back(asteroids[i]);
                            cond = false; 
                            cout << "pushing bc negative" << endl;
                        }
                        else if (abs(result.back()) < abs(asteroids[i])) {
                            result.pop_back();
                        }
                        else if (abs(result.back()) == abs(asteroids[i])) {
                            result.pop_back();
                            cond = false;
                        }
                        else {
                            cond = false;
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