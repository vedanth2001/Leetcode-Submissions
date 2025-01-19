class Solution {
public:
    bool wordBreakHelper(string s, unordered_set<string> st, int i, vector<int> &mem){
        if(i==s.length()) return true;
        string temp = "";
        if(mem[i]!=-1) return mem[i];
        for(int j = i;j<s.length();j++){
            temp+=s[j];
            if(st.find(temp)!=st.end()){
                if(wordBreakHelper(s, st, j+1, mem)) return mem[i] = true;
            }
        }
        return mem[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto word: wordDict){
            st.insert(word);
        }
        int start = 0;
        vector<int> mem(s.length()+1, -1);
        return wordBreakHelper(s, st, start, mem);
    }
};