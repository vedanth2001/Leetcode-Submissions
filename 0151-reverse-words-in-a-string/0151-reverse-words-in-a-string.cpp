class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        stack<string> words;
        string result;

        int i = 0;
        while (i < n) {
            // Skip spaces before each word
            while (i < n && s[i] == ' ') i++;

            // Collect the current word
            string curr;
            while (i < n && s[i] != ' ') {
                curr += s[i];
                i++;
            }

            // Push non-empty word onto the stack
            if (!curr.empty()) {
                words.push(curr);
            }
        }

        // Pop from stack and build the result
        while (!words.empty()) {
            result += words.top();
            words.pop();
            if (!words.empty()) result += ' ';  // Add space between words
        }

        return result;
    }
};
