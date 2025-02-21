
class FindElements {
public:
    unordered_map<int, bool> values; 

    void recover(TreeNode* root, int val) {
        if (!root) return;
        root->val = val;
        values[val] = true;  
        recover(root->left, 2 * val + 1);
        recover(root->right, 2 * val + 2);
    }

    FindElements(TreeNode* root) {
        if (root) {
            recover(root, 0);
        }
    }
    
    bool find(int target) {
        return values.find(target) != values.end();
    }
};