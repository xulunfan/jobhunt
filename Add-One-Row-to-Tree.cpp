/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int maxdepth(TreeNode* root){
    if(!root) return 0;
    int depth=1;
    depth=max(depth,1+maxdepth(root->left));
    depth=max(depth,1+maxdepth(root->right));
    return depth;
}
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(!root) return 0;
        
        if(d==1){
            TreeNode* t=new TreeNode(v);
            t->left=root;
            return t;
        }
        
        if(d==2){
            TreeNode* l=new TreeNode(v);
            l->left=root->left;
            root->left=l;
            TreeNode* r=new TreeNode(v);
            r->right=root->right;
            root->right=r;
            return root;
        }
        int mdl=maxdepth(root->left),mdr=maxdepth(root->right);
    
        if(mdl+2>=d){
            root->left=addOneRow(root->left,v,d-1);
        }
        if(mdr+2>=d){
            root->right=addOneRow(root->right,v,d-1);
        }
        return root;
    }
};
