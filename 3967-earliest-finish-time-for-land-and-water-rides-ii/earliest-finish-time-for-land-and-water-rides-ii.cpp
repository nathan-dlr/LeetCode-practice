class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int earliest_land_end = std::numeric_limits<int>::max() >> 1;
        int earliest_water_end = std::numeric_limits<int>::max() >> 1;
        int result = std::numeric_limits<int>::max() >> 1;
        for (int i = 0; i < landStartTime.size(); i++) {
            int endTime = landStartTime[i] + landDuration[i];
            if (endTime < earliest_land_end) {
                earliest_land_end = endTime;
            }
        }
        for (int j = 0; j < waterStartTime.size(); j++) {
            int endTime;
            if (waterStartTime[j] <= earliest_land_end) {
                endTime = earliest_land_end + waterDuration[j];
            }
            else {
                endTime = waterStartTime[j] + waterDuration[j];
            }

            if (endTime < result) {
                result = endTime;
            }
        }
        for (int i = 0; i < waterStartTime.size(); i++) {
            int endTime = waterStartTime[i] + waterDuration[i];
            if (endTime < earliest_water_end) {
                earliest_water_end = endTime;
            }
        }
        for (int j = 0; j < landStartTime.size(); j++) {
            int endTime;
            if (landStartTime[j] <= earliest_water_end) {
                endTime = earliest_water_end + landDuration[j];
            }
            else {
                endTime = landStartTime[j] + landDuration[j];
            }
            
            if (endTime < result) {
                result = endTime;
            }
        }
        return result;
    }
};