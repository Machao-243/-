/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct queNode{
    int val;
    struct TreeNode *node;
    struct queNode *next;
} queNode;

//要正确申请一个空间需要一个一级指针， 要操作这个一级指针的地址，就必须用二级指针来完成，不能使用一级指针，否则不能正确操作一个空间.
void init(struct queNode **p, int val, struct TreeNode *node){
    //申请一个空间
    (*p) = (struct queNode *)malloc(sizeof(struct queNode));
    (*p) -> val = val;
    (*p) -> node = node;
    (*p) -> next = NULL; 
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(root == NULL){
        return false;
    }

    queNode *queLeft, *queRight;//队列首尾指针
    init(&queLeft, root -> val, root);
    queRight = queLeft;

   while(queLeft != NULL){

        struct TreeNode *curTree = queLeft -> node;
        int temp = queLeft -> val;
        //判断是否是叶子节点： 是则判断当前路径的和是否与目标值相等，不是则考虑入队
        if(curTree -> left == NULL && curTree -> right == NULL){
            if(temp == targetSum){
                return true;
            }
        }
        //以下这两个是独立的 都是从根出发的
        if(curTree -> left != NULL){
            init(&queRight -> next, temp + curTree -> left -> val, curTree -> left);
            queRight = queRight -> next;
        }

        if(curTree -> right != NULL){
            init(&queRight -> next, temp + curTree -> right -> val, curTree -> right);
            queRight = queRight -> next;
        }
        //当这两个环节结束之后，队列的头指针向后移动，就可以拿到下一层的左右孩子了，再入队。
        queLeft = queLeft -> next;
    }    
    return false;
}
-----------------------------------------------------------------------------------------------------------------------------------------
    //方法二：递归解决
    bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(root == NULL){
        return false;
    }
    if(root -> left == NULL && root -> right == NULL){
        return root -> val == targetSum;
    }
    return hasPathSum(root -> left, targetSum - root -> val) || hasPathSum(root -> right, targetSum - root -> val);
    
    }
