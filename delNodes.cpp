struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;
        helper(root, toDeleteSet, forest, true);
        return forest;
}
private:
    TreeNode* helper(TreeNode* node, unordered_set<int>& toDeleteSet, vector<TreeNode*>& forest, bool isRoot) {
        if(!node) return nullptr;
        bool toDelete = toDeleteSet.count(node->val);
        if(isRoot && !toDelete) {
            forest.push_back(node);
        }
        node->left = helper(node->left, toDeleteSet, forest, toDelete);
        node->right = helper(node->right, toDeleteSet, forest, toDelete);
        return toDelete ? nullptr : node;
    }
};
