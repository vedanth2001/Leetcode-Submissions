class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {

        vector<string>result;

        result.push_back(words[0]);

        for(int i=1;i<words.size();i++){
            string sortedWord = words[i];
            string previousSortedWord = words[i-1];

            sort(sortedWord.begin(),sortedWord.end());
            sort(previousSortedWord.begin(),previousSortedWord.end());

            if(sortedWord!=previousSortedWord){
                result.push_back(words[i]);
            }
        };
        

        return result;
    }
};