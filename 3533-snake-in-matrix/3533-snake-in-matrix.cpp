class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        
        int num = commands.size();
        pair<int,int> curr= {0,0};
        for(int i = 0; i < num; i++) {
            if(commands[i] == "UP") {
                if(curr.second > 0) curr.second -= 1; // Check boundary
            } else if(commands[i] == "RIGHT") {
                if(curr.first < n - 1) curr.first += 1; // Check boundary
            } else if(commands[i] == "DOWN") {
                if(curr.second < n - 1) curr.second += 1; // Check boundary
            } else if(commands[i] == "LEFT") {
                if(curr.first > 0) curr.first -= 1; // Check boundary
            }
        }
        int x = curr.first;
        int y = curr.second;
        return (curr.second * n) + curr.first;
    

    }
};