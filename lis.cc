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
    if (root) return 0;
    root->lsi = 1;
    if (root->lchild)
        root->lsi += f(root->lchild->lchild)+f(root->lchild->rchild);
    if (root->rchild)
        root->lsi += f(root->rchild->lchild)+f(root->rchild->rchild);
    return root->lsi;    
}

int lsi(node_t *root) {
    if (!root) return 0;
    int rst = 0;
    if (root->lchild) rst += root->lchild->lsi;
    if (root->rchild) rst += root->rchild->lsi;
    return rst > root->lsi ? rst : root->lsi;
}
