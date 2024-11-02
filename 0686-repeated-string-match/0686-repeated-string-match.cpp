class Solution {
public:
    int repeatedStringMatch(string a, string b) {
       int n1 = (b.length()/a.length())+2;
       int count = 1;
       string var = a;
       for(int i =1;i<=n1;i++){
        if(var.find(b)!=string::npos){
            return count;
        }
        var=var+a;
        count++;
       }
       
       return -1;


    }
};