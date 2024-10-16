class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Step 1: Sort people by height in descending order, and by k in ascending order
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];  // If heights are the same, sort by k
            }
            return a[0] > b[0];  // Otherwise, sort by height in descending order
        });

        // Step 2: Reconstruct the queue
        vector<vector<int>> queue;
        for (const auto& person : people) {
            queue.insert(queue.begin() + person[1], person);  // Insert person at their k position
        }

        return queue;
    }
};
