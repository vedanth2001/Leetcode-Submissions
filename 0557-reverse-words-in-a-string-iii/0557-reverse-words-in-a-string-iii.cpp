class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int start = 0;

        while (start < n) {
            // Skip any leading spaces for each word
            while (start < n && s[start] == ' ') start++;

            // Set end to find the end of the current word
            int end = start;
            while (end < n && s[end] != ' ') end++;

            // Reverse the current word
            reverse(s.begin() + start, s.begin() + end);

            // Move start to the next word
            start = end + 1;
        }

        return s;
    }
};
