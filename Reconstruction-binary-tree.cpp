/**********************************************************************************
前序遍历确定根节点，中序遍历确定左右子树，然后递归实现二叉树的重建
***********************************************************************************/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) 
    {
		int lengthp = pre.size();
        int lengthi = in.size();
        if(lengthp == 0 || lengthi == 0 || lengthp != lengthi)
            return NULL;
        vector<int>::iterator pstart = pre.begin();
        vector<int>::iterator pend = pre.end()-1;
        vector<int>::iterator istart = in.begin();
        vector<int>::iterator iend = in.end()-1;
        
        return CoreBinaryTree(pstart,pend,istart,iend);

    }
private:
    TreeNode* CoreBinaryTree(vector<int>::iterator pstart,vector<int>::iterator pend,
                              vector<int>::iterator istart,vector<int>::iterator iend)
    {
        TreeNode* root = new TreeNode(*pstart);
        if(pstart == pend)
        {
            if(istart == iend && *pstart == *istart)
                return root;
        }
        vector<int>::iterator rootinorder = istart;
        while(rootinorder < iend && *rootinorder != *pstart)
        	++rootinorder;
        if(rootinorder == iend && *rootinorder != *pstart)
            return NULL;
        
        int leftLength = rootinorder - istart;
        vector<int>::iterator leftpreorderEnd = pstart + leftLength;
        //构建左子树
        if(leftLength > 0)
        {
            root->left = CoreBinaryTree(pstart+1,leftpreorderEnd,istart,rootinorder-1);
        }
        if(leftLength < pend - pstart)
        {
             root->right = CoreBinaryTree(leftpreorderEnd+1,pend,rootinorder+1,iend);
        }
        return root;
    }
    
};
