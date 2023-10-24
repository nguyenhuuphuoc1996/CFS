#ifndef RED_BLACK_TREE_DS
#define RED_BLACK_TREE_DS
#include <iostream>
#include <cstdint>

enum COLOR
{
    BLACK = 0,
    RED
};

struct Node
{
    int rbt_currentTimeVirtual;
    uint64_t rbt_remainTimeVirtual;
    uint64_t rbt_task_number;
    COLOR color;
    Node *left;
    Node *right;
    Node *parent;
};

class Red_Black_Tree
{
public:
    Red_Black_Tree();
    ~Red_Black_Tree();
    void RBTInsertion(Node *p_Node);
    void RBTDeletion(Node *p_Node_z);
    void RBTRBPrintNode(Node *p_Node);
    Node *RBTReturnMostLeftNode();
    Node *RBTrootIs();

private:
    void RBTLeftRotation(Node *p_Node);
    void RBTRightRotation(Node *p_Node);
    void RBTFixInsertion(Node *p_Node_z);
    void RBTFixDeletion(Node *p_Node_x);
    void RBTTransplant(Node *p_Node_u, Node *p_Node_v);
    Node *RBTTreeMinimum(Node *p_Node);

public:
    Node *T;
    Node *root;
    Node *Nil;
};

#endif