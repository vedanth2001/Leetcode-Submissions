class Solution {
public:
    bool matching(char closingBracket, stack<char> &openingBrackets){
        if (openingBrackets.empty()) return false;
        if(closingBracket==')' && openingBrackets.top()=='(' || 
           closingBracket==']' && openingBrackets.top()=='[' ||
           closingBracket=='}' && openingBrackets.top()=='{'){
            openingBrackets.pop();
            return true;
        }
        return false;
           
    }
    bool isValid(string s) {
        int n = s.length();
        stack<char> openingBrackets;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                openingBrackets.push(s[i]);
            }
            else if(s[i]==')' || s[i]=='}' || s[i]==']'){
                if(!matching(s[i], openingBrackets)){
                    return false;
                }
            }
        }
        if(!openingBrackets.empty()) return false;
        return true;
    }
};