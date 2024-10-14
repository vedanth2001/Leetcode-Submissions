class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        // Extract start and end times of both events
        string start1 = event1[0], end1 = event1[1];
        string start2 = event2[0], end2 = event2[1];

        // Check if there is any overlap between the two events
        if (start1 <= end2 && end1 >= start2) {
            return true;  // Events conflict
        }
        return false;     // No conflict
    }
};