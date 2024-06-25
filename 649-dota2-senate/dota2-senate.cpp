class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> R;
        queue<int> D;
        int n = senate.size();
        for (int i = 0; i < senate.size(); i++) {
            if (senate[i] == 'R') {
                R.push(i);
            }
            else {
                D.push(i);
            }
        }

        while (D.empty() == false && R.empty() == false) {
            if (R.front() < D.front()) {
                D.pop();
                R.pop();
                R.push(n);
                n++;
            }
            else {
                R.pop();
                D.pop();
                D.push(n);
                n++;
            }
        }
        if (D.empty()) {
            return "Radiant";
        }
        else {
            return "Dire";
        }
    }
};