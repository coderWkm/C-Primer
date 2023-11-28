#ifndef CLASS_EXER
#define CLASS_EXER

#include <string>

class TreeNode {
public:
    TreeNode() : value(std::string("")), count(0), 
                 left(nullptr),  right(nullptr) { } 
    // 类值拷贝
    TreeNode(const TreeNode& copy) : 
        value(std::string(copy.value)), 
        count(copy.count), 
        left (new TreeNode(*(copy.left))),  // 指向左节点的拷贝
        right (new TreeNode(*(copy.right)))    
        { }
private:
    std::string value;
    int         count;
    TreeNode    *left;
    TreeNode    *right;
};

class BinStrTree {
public:
    BinStrTree(): root(nullptr) {}
    BinStrTree(const BinStrTree &copy) : 
        root(new TreeNode(*(copy.root)))
        {}
private:
    TreeNode *root;
};
#endif