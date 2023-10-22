#include "RedBlackTreeDS.h"
Red_Black_Tree::Red_Black_Tree()
{
    // Sensitle Nil node
    Nil = new Node();
    Nil->left = nullptr;
    Nil->right = nullptr;
    Nil->parent = root;
    Nil->color = BLACK;

    T = Nil;
    root = T;
}
Red_Black_Tree::~Red_Black_Tree()
{
    // empty destructor
}
void Red_Black_Tree::RBTRBPrintNode(Node *p_Node)
{
    if (p_Node != Nil)
    {
        RBTRBPrintNode(p_Node->left);
        std::cout << p_Node->rbt_currentTimeVirtual << std::endl;
        RBTRBPrintNode(p_Node->right);
    }
}
Node *Red_Black_Tree::RBTrootIs()
{
    return T;
}
void Red_Black_Tree::RBTLeftRotation(Node *p_Node)
{
    // rotate the connection between z and z.right
    Node *y = p_Node->right;
    p_Node->right = y->left;
    if (y->left != Nil)
    {
        y->left->parent = p_Node;
    }

    if (p_Node->parent == Nil)
    {
        T = y;
    }
    else if (p_Node == p_Node->parent->left)
    {
        p_Node->parent->left = y;
    }
    else
    {
        p_Node->parent->right = y;
    }
    y->parent = p_Node->parent;
    y->left = p_Node;
    p_Node->parent = y;
}
void Red_Black_Tree::RBTRightRotation(Node *p_Node)
{
    // rotate the connection between z and z.left
    Node *y = p_Node->left;
    p_Node->left = y->right;
    if (y->right != Nil)
    {
        y->right->parent = p_Node;
    }

    if (p_Node->parent == Nil)
    {
        T = y;
    }
    else if (p_Node == p_Node->parent->left)
    {
        p_Node->parent->right = y;
    }
    else
    {
        p_Node->parent->left = y;
    }
    y->parent = p_Node->parent;
    y->right = p_Node;
    p_Node->parent = y;
}
void Red_Black_Tree::RBTFixInsertion(Node *p_Node)
{
    Node *tmp = p_Node;
    // prove that only the case of z and z.p are RED is violate in this case
    while (tmp->parent->color == RED)
    {
        if (tmp->parent == tmp->parent->parent->left)
        {
            // examinate z's uncle
            Node *y = tmp->parent->parent->right;
            if (y->color == RED)
            {
                // Downstream color level of both parent and uncle
                y->color = BLACK;
                tmp->parent->color = BLACK;
                // change colour of grandfather to maintain property number 5
                tmp->parent->parent->color = RED;
                // move that pointer to current grandfather and check whether violate or not
                tmp = tmp->parent->parent;
            }
            else
            {
                // because uncle and parent are different colour => cannot downstream colour level
                if (tmp == tmp->parent->right)
                {
                    tmp = tmp->parent;
                    // Rotate two RED node => do not affect to any properties
                    RBTLeftRotation(tmp);
                }
                // change current node to BLACK as its chile is RED after rotate
                tmp->parent->color = BLACK;
                // change grandparent to RED and utilize Right rotate
                tmp->parent->parent->color = RED;
                RBTRightRotation(tmp->parent->parent);
            }
        }
        else
        {
            // examinate z's uncle
            Node *y = tmp->parent->parent->left;
            if (y->color == RED)
            {
                // Downstream color level
                y->color = BLACK;
                tmp->parent->color = BLACK;
                // change colour of grandfather to maintain property number 5
                tmp->parent->parent->color = RED;
                // move that pointer to current grandfather and check whether violate or not
                tmp = tmp->parent->parent;
            }
            else
            {
                if (tmp == tmp->parent->left)
                {
                    tmp = tmp->parent;
                    // Rotate two RED node => do not affect to any properties
                    RBTRightRotation(tmp);
                }
                // change current node to BLACK as its chile is RED after rotate
                tmp->parent->color = BLACK;
                // change grandparent to RED and utilize Right rotate
                tmp->parent->parent->color = RED;
                RBTLeftRotation(tmp->parent->parent);
            }
        }
    }
    // USE CASE 1: if there is only one new node in trees
    // USE CASE 2: TBD
    T->color = BLACK;
}
void Red_Black_Tree::RBTInsertion(Node *p_Node)
{
    Node *tmp = T;
    Node *tmoNil = Nil;
    while (tmp != Nil)
    {
        // back up node to use as parent of new node
        tmoNil = tmp;
        // New node is in right side
        if (p_Node->rbt_currentTimeVirtual > tmp->rbt_currentTimeVirtual)
        {
            tmp = tmp->right;
        }
        // New node is in left side
        else
        {
            tmp = tmp->left;
        }
    }
    if (tmoNil == Nil)
    {
        T = p_Node;
    }
    else if (tmoNil->rbt_currentTimeVirtual > p_Node->rbt_currentTimeVirtual)
    {
        tmoNil->left = p_Node;
    }
    else
    {
        tmoNil->right = p_Node;
    }
    // add new node in trees
    p_Node->parent = tmoNil;
    p_Node->color = RED;
    p_Node->left = Nil;
    p_Node->right = Nil;

    // Fix violations when adding new node
    RBTFixInsertion(p_Node);
}

void Red_Black_Tree::RBTTransplant(Node *p_Node_u, Node *p_Node_v)
{
    // Replace node u by no v
    // left and right child of v are not update
    if (p_Node_u->parent == Nil)
    {
        T = p_Node_v;
    }
    else if (p_Node_u == p_Node_u->parent->right)
    {
        p_Node_u->parent->right = p_Node_v;
    }
    else
    {
        p_Node_u->parent->left = p_Node_v;
    }

    // Event Nil node can have a parent in RBT
    p_Node_v->parent = p_Node_u->parent;
}

void Red_Black_Tree::RBTDeletion(Node *p_Node)
{
    // TBD
}

Node *Red_Black_Tree::RBTReturnMostLeftNode()
{
    Node *rbt_mostLeftNodeInTree;
    return rbt_mostLeftNodeInTree;
}
