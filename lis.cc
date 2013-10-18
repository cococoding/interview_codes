//  Largest Independent Set
// Given a binary tree, find largest set whose nodes are not connected
// Design:
//  1. For every node p, f(p) represent size of the largest set including p as the root node, then 
//   f(p) = f(p->lchild->lchild)+f(p->lchild->rchild)+f(p->rchild->lchild)+f(p->rchild->rchild)+1
//   finally, the lsi(root) = max{f(root), f(root->lchild)+f(root->rchild)} 
//  2. Another way, 

struct node_t {
    node_t * lchild;
    node_t * rchild;
    int val;
    int lsi;
}

int f(node_t * root) {
    if (!root) return 0;
    root->lsi = 1;
    f(root->lchild);
    f(root->rchild);
        
    if (root->lchild) {
        if (root->lchild->lchild) root->lsi += root->lchild->lchild->lsi;
        if (root->lchild->rchild) root->lsi += root->lchild->rchild->lsi;
    }
    if (root->rchild) {
        if (root->rchild->lchild) root->lsi += root->rchild->lchild->lsi;
        if (root->rchild->rchild) root->lsi += root->rchild->rchild->lsi;
    }
    return 0;    
}

int lsi(node_t *root) {
    if (!root) return 0;
    f(root);
    int rst = 0;
    if (root->lchild) rst += root->lchild->lsi;
    if (root->rchild) rst += root->rchild->lsi;
    return rst > root->lsi ? rst : root->lsi;
}
