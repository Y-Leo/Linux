#include <stdio.h>
#include <iostream>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
        }
};

class Solution {
    public:
        bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
        {
            if(!pRoot2)return true;
            if(!pRoot1)return false;
            if(pRoot1->val==pRoot2->val)
            {
                if(isSubtree(pRoot1->left,pRoot2->left)&&isSubtree(pRoot1->right,pRoot2->right))
                    return true;
            }
            return false;
        }
        bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
        {
            if(!pRoot2||!pRoot1){return false;}

            if(pRoot1->val==pRoot2->val)
            {
                if(isSubtree(pRoot1,pRoot2))
                    return true;
            }
            if(HasSubtree(pRoot1->left,pRoot2))
            {
                return true;
            }
            if(HasSubtree(pRoot1->right,pRoot2))
            {
                return true;
            }
            return false;
        }
};


int main()
{
    return 0;
}
