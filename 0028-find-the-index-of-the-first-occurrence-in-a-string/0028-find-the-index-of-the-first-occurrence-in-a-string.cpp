class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0; // Edge case: empty needle
        int d = 256;       // Number of characters in the input alphabet
        int q = 101;       // A prime number for modulo operation
        int h = 1;         // h will be d^(n-1) % q
        int hay = 0;       // Hash value for haystack
        int nee = 0;       // Hash value for needle

        int n = needle.size();
        int m = haystack.size();

        // Edge case: if needle is longer than haystack, return -1
        if (n > m) return -1;

        // Calculate h = d^(n-1) % q
        for (int i = 1; i < n; i++) {
            h = (h * d) % q;
        }

        // Calculate initial hash values for needle and the first window of haystack
        for (int i = 0; i < n; i++) {
            hay = (d * hay + haystack[i]) % q;
            nee = (d * nee + needle[i]) % q;
        }

        // Slide the pattern over text one by one
        for (int i = 0; i <= m - n; i++) {
            // Check the hash values of current window of haystack and needle
            if (hay == nee) {
                // If the hash values match, check the characters one by one
                bool match = true;
                for (int j = 0; j < n; j++) {
                    if (haystack[i + j] != needle[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) return i; // Found the needle
            }

            // Calculate hash for the next window of text
            // Remove leading character, add trailing character
            if (i < m - n) {
                hay = (d * (hay - haystack[i] * h) + haystack[i + n]) % q;

                // We might get a negative hash, so we convert it to positive
                if (hay < 0) {
                    hay = (hay + q);
                }
            }
        }

        return -1; // If needle is not found in haystack
    }
};
