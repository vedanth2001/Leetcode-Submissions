class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        queue<int> q;
        for(int i =1;i<=n*n;i++){
            q.push(i);
        }
        vector<vector<int>> v(n, vector<int> (n));
        int top=0;
        int down=n-1;
        int left =0;
        int right =n-1;
        while(left<=right && top<=down){
            for(int i =left;i<=right;i++){
                v[top][i] = q.front();
                q.pop();
            }
            top++;
            for(int i=top;i<=down;i++){
                v[i][right] = q.front();
                q.pop();
            }
            right--;
            if(top<=down){
                for(int i=right;i>=left;i--){
                    v[down][i] = q.front();
                    q.pop();
                }
                down--;
            }
            if(left<=right){
                for(int i = down;i>=top;i--){
                    v[i][left] = q.front();
                    q.pop();
                }
                left++;
            }
        }
        return v;
    }
};