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
    y->parent = p_Node->parent;

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

    y->right = p_Node;
    p_Node->parent = y;
}
void Red_Black_Tree::RBTFixInsertion(Node *p_Node_z)
{
    // prove that only the case of z and z.p are RED is violate in this case
    while (p_Node_z->parent->color == RED)
    {
        if (p_Node_z->parent == p_Node_z->parent->parent->left)
        {
            // examinate z's uncle
            Node *y = p_Node_z->parent->parent->right;
            if (y->color == RED)
            {
                // Downstream color level of both parent and uncle
                y->color = BLACK;
                p_Node_z->parent->color = BLACK;
                // change colour of grandfather to maintain property number 5
                p_Node_z->parent->parent->color = RED;
                // move that pointer to current grandfather and check whether violate or not
                p_Node_z = p_Node_z->parent->parent;
            }
            else
            {
                // because uncle and parent are different colour => cannot downstream colour level
                if (p_Node_z == p_Node_z->parent->right)
                {
                    p_Node_z = p_Node_z->parent;
                    // Rotate two RED node => do not affect to any properties
                    RBTLeftRotation(p_Node_z);
                }
                // change current node to BLACK as its chile is RED after rotate
                p_Node_z->parent->color = BLACK;
                // change grandparent to RED and utilize Right rotate
                p_Node_z->parent->parent->color = RED;
                RBTRightRotation(p_Node_z->parent->parent);
            }
        }
        else
        {
            // examinate z's uncle
            Node *y = p_Node_z->parent->parent->left;
            if (y->color == RED)
            {
                // Downstream color level
                y->color = BLACK;
                p_Node_z->parent->color = BLACK;
                // change colour of grandfather to maintain property number 5
                p_Node_z->parent->parent->color = RED;
                // move that pointer to current grandfather and check whether violate or not
                p_Node_z = p_Node_z->parent->parent;
            }
            else
            {
                if (p_Node_z == p_Node_z->parent->left)
                {
                    p_Node_z = p_Node_z->parent;
                    // Rotate two RED node => do not affect to any properties
                    RBTRightRotation(p_Node_z);
                }
                // change current node to BLACK as its chile is RED after rotate
                p_Node_z->parent->color = BLACK;
                // change grandparent to RED and utilize Right rotate
                p_Node_z->parent->parent->color = RED;
                RBTLeftRotation(p_Node_z->parent->parent);
            }
        }
    }
    // USE CASE 1: if there is only one new node in trees
    // USE CASE 2: TBD
    T->color = BLACK;
}
void Red_Black_Tree::RBTInsertion(Node *p_Node)
{
    Node *rbt_x = T;
    Node *rbt_y = Nil;
    while (rbt_x != Nil)
    {
        // back up node to use as parent of new node
        rbt_y = rbt_x;
        // New node is in right side
        if (p_Node->rbt_currentTimeVirtual < rbt_x->rbt_currentTimeVirtual)
        {
            rbt_x = rbt_x->left;
        }
        // New node is in left side
        else
        {
            rbt_x = rbt_x->right;
        }
    }
    p_Node->parent = rbt_y;
    if (rbt_y == Nil)
    {
        T = p_Node;
    }
    else if (p_Node->rbt_currentTimeVirtual < rbt_y->rbt_currentTimeVirtual)
    {
        rbt_y->left = p_Node;
    }
    else
    {
        rbt_y->right = p_Node;
    }
    // add new node in trees
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
    else if (p_Node_u == p_Node_u->parent->left)
    {
        p_Node_u->parent->left = p_Node_v;
    }
    else
    {
        p_Node_u->parent->right = p_Node_v;
    }

    // Event Nil node can have a parent in RBT
    p_Node_v->parent = p_Node_u->parent;
}

void Red_Black_Tree::RBTFixDeletion(Node *p_Node_x)
{
    Node *rbt_Node_w;
    while (p_Node_x != T && p_Node_x->color == BLACK)
    {
        if (p_Node_x == p_Node_x->parent->left)
        {
            rbt_Node_w = p_Node_x->parent->right;
            if (rbt_Node_w->color == RED)
            {
                rbt_Node_w->color = BLACK;
                p_Node_x->parent->color = RED;
                RBTLeftRotation(p_Node_x->parent);
                rbt_Node_w = p_Node_x->parent->right;
            }
            if (rbt_Node_w->left->color == BLACK && rbt_Node_w->right->color == BLACK)
            {
                rbt_Node_w->color = RED;
                p_Node_x = p_Node_x->parent;
            }
            else
            {
                if (rbt_Node_w->right->color == BLACK)
                {
                    rbt_Node_w->left->color = BLACK;
                    rbt_Node_w->color = RED;
                    RBTRightRotation(rbt_Node_w);
                    rbt_Node_w = p_Node_x->parent->right;
                }
                rbt_Node_w->color = p_Node_x->parent->color;
                p_Node_x->parent->color = BLACK;
                rbt_Node_w->right->color = BLACK;
                RBTLeftRotation(p_Node_x->parent);
                p_Node_x = T;
            }
        }
        else
        {
            rbt_Node_w = p_Node_x->parent->left;
            if (rbt_Node_w->color == RED)
            {
                rbt_Node_w->color = BLACK;
                p_Node_x->parent->color = RED;
                RBTRightRotation(p_Node_x->parent);
                rbt_Node_w = p_Node_x->parent->left;
            }
            if (rbt_Node_w->right->color == BLACK && rbt_Node_w->left->color == BLACK)
            {
                rbt_Node_w->color = RED;
                p_Node_x = p_Node_x->parent;
            }
            else
            {
                if (rbt_Node_w->left->color == BLACK)
                {
                    rbt_Node_w->right->color = BLACK;
                    rbt_Node_w->color = RED;
                    RBTLeftRotation(rbt_Node_w);
                    rbt_Node_w = p_Node_x->parent->left;
                }
                rbt_Node_w->color = p_Node_x->parent->color;
                p_Node_x->parent->color = BLACK;
                rbt_Node_w->left->color = BLACK;
                RBTRightRotation(p_Node_x->parent);
                p_Node_x = T;
            }
        }
    }
    p_Node_x->color = BLACK;
}

void Red_Black_Tree::RBTDeletion(Node *p_Node_z)
{
    Node *rbt_Node_x;
    Node *rbt_Node_y = p_Node_z;
    COLOR rbt_y_original_color = rbt_Node_y->color;
    if (p_Node_z->left == Nil)
    {
        rbt_Node_x = p_Node_z->right;
        RBTTransplant(p_Node_z, p_Node_z->right);
    }
    else if (p_Node_z->right == Nil)
    {
        rbt_Node_x = p_Node_z->left;
        RBTTransplant(p_Node_z, p_Node_z->left);
    }
    else
    {
        rbt_Node_y = RBTTreeMinimum(p_Node_z->right);
        rbt_y_original_color = rbt_Node_y->color;
        rbt_Node_x = rbt_Node_y->right;
        if (rbt_Node_y != p_Node_z->right)
        {
            RBTTransplant(rbt_Node_y, rbt_Node_y->right);
            rbt_Node_y->right = p_Node_z->right;
            rbt_Node_y->right->parent = rbt_Node_y;
        }
        else
        {
            rbt_Node_x->parent = rbt_Node_y;
        }
        RBTTransplant(p_Node_z, rbt_Node_y);
        rbt_Node_y->left = p_Node_z->left;
        rbt_Node_y->left->parent = rbt_Node_y;
        rbt_Node_y->color = p_Node_z->color;
    }
    if (rbt_y_original_color == BLACK)
    {
        RBTFixDeletion(rbt_Node_x);
    }
}

Node *Red_Black_Tree::RBTTreeMinimum(Node *p_Node)
{
    while (p_Node->left != Nil)
    {
        p_Node = p_Node->left;
    }
    return p_Node;
}

Node *Red_Black_Tree::RBTReturnMostLeftNode()
{
    Node *rbt_mostLeftNodeInTree = T;
    while (rbt_mostLeftNodeInTree->left != Nil)
    {
        rbt_mostLeftNodeInTree = rbt_mostLeftNodeInTree->left;
    }
    return rbt_mostLeftNodeInTree;
}
