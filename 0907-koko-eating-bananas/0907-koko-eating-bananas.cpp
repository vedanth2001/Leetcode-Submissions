class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // \U0001f34c Binary Search between 1 and the maximum pile size
        int left = 1, right = *max_element(piles.begin(), piles.end());

        // \U0001f504 Binary search loop to find the minimum eating speed
        while (left < right) {
            int mid = (left + right) / 2; // ➗ Calculate mid value for k (speed)
            int total_hours = 0;

            // \U0001f504 Calculate the total hours required for current speed `mid`
            for (int pile : piles) {
                total_hours += (pile + mid - 1) / mid;  // \U0001f552 Calculate hours for each pile
            }

            // \U0001f9d0 Check if the current speed satisfies the condition
            if (total_hours <= h) {
                right = mid;  // \U0001f448 Move to a slower speed
            } else {
                left = mid + 1;  // \U0001f449 Increase the speed
            }
        }

        return left;  // \U0001f3af Minimum speed k that satisfies the condition
    }
};