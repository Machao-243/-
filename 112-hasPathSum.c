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
    (*p) -> node =…    }
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