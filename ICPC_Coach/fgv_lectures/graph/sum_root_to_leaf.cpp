/**
 * Link: https://leetcode.com/problems/sum-root-to-leaf-numbers
 *
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
    int result;
    void getNumberRec(TreeNode* root, string curStr) {
        if(!root) return;
        curStr += '0' + root->val;
        
        // leaf
        if(!root->left && !root->right) {    
            //cout << curStr << endl;
            int curVal = 0;
            int n = (int) curStr.size();
            for(int i = 0; i < n; i++) {
                curVal += (curStr[i] - '0') * pow(10, n-i-1);
            }            
            result += curVal;
            return;
        }
        
        // not leaf
        getNumberRec(root->left, curStr);
        getNumberRec(root->right, curStr);
        return;
    }
    int sumNumbers(TreeNode* root) {
        result = 0;
        string str = "";
        getNumberRec(root, str);
        return result;
    }
};