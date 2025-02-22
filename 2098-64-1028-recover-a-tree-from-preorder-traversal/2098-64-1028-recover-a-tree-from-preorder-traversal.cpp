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
int get_place(string &s,int &i){
    int x=0;
    while(s[i]=='-' && i<s.size()){
     x++;
     i++;
    }
    return x;
}
int get_number(string& s,int &i){
    int x=0;
    while(s[i]!='-' && i<s.size()){
      x=x*10+(s[i]-'0');
     i++;
    }
    return x;
}
// void reset_i(string s,int &i){
//     while(s[i]=='-'){
//      i--;
//     }
//     i++;
// }
TreeNode*get_ans(string & s,int lvl,int &i){
if(i>=s.size()) return NULL;
int place=get_place(s,i);
if(place<lvl){
// reset_i(s,i);
 i -= place; // changed 
return NULL;
} 
int num=get_number(s,i);
TreeNode*root=new TreeNode(num);
root->left=get_ans(s,lvl+1,i);
root->right=get_ans(s,lvl+1,i);
return root;
}
    TreeNode* recoverFromPreorder(string s) {
        int i=0;
        TreeNode*root=get_ans(s,0,i);
        return root;
    }
};