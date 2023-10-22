#ifndef RED_BLACK_TREE_DS
#define RED_BLACK_TREE_DS
#include <iostream>

enum COLOR
{
    BLACK = 0,
    RED
};

struct Node
{
    int key;
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
    void Insertion(Node *p_Node);
    void Deletion(Node p_Node);
    void RBPrintNode(Node *p_Node);
    Node *rootIs();

private:
    void LeftRotation(Node *p_Node);
    void RightRotation(Node *p_Node);
    void FixInsertion(Node *p_Node);
    void Transplant(Node *p_Node_u, Node *p_Node_v);

private:
    Node *T;
    Node *root;
    Node *Nil;
};

#endif