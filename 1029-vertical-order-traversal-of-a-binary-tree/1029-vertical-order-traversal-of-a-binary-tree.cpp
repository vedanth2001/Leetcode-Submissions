/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        map<int, map<int, multiset<int>>> mp; // x-coordinate -> y-coordinate -> values
        queue<pair<TreeNode*, pair<int, int>>> q; // Node, {x, y}
        q.push({root, {0, 0}});
        
        // BFS traversal
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* curr = it.first;
            int x = it.second.first;
            int y = it.second.second;
            
            // Insert the value into the multiset
            mp[x][y].insert(curr->val);
            
            // Push left and right children into the queue with updated coordinates
            if (curr->left) q.push({curr->left, {x - 1, y + 1}});
            if (curr->right) q.push({curr->right, {x + 1, y + 1}});
        }
        
        // Build the result
        for (auto& p : mp) {
            vector<int> curr;
            for (auto& q : p.second) {
                curr.insert(curr.end(), q.second.begin(), q.second.end());
            }
            result.push_back(curr);
        }
        
        return result;
    }
};