class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        string ss_new = ss.substr(1, ss.size() - 2);
        return ss_new.find(s) != string::npos;
    }
};
